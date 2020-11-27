#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

int main()
{
    FILE *picture;
    int num;
    int fd_tab[2];
    char name[100]; //tablica na nazwę pliku

    if (pipe(fd_tab) == -1)
    {
        write(2, "error przy tworzeniu pipe\n", 27);
        exit(EXIT_FAILURE);
    } //nienazwany potok

    int pid = fork();
    if (pid > 0) //rodzic
    {
        close(fd_tab[0]); /* Zamknięcie nieużywanego czytania */
        write(1, "Podaj nazwę pliku z obrazkiem: \n", 33);
        char c = '\0';
        int j = 0;
        do
        {
            read(STDIN_FILENO, &c, 1);
            name[j] = c;
            j++;
        } while (c != '\n');
        name[j - 1] = '\0';
        int fd_picture = open(name, O_RDONLY);
        if (fd_picture > 0)
        {
            while (read(fd_picture, &num, 1) > 0)
            {
                write(fd_tab[1], &num, 1); //wysyłanie na pipe
            }
            close(fd_picture);
        }
        else
        {
            write(1, "Blad odczytu pliku\n", 19);
        }
        /*       if ((picture = fopen(name, "r")) == NULL) //sprawdzenie poprawnego otworzenia
        {
            write(1, "Plik nie został otworzony do czytania\n", 38);
            exit(EXIT_FAILURE);
        }
        while (!feof(picture)) //czytanie do końca pliku
        {
            num = getc(picture);
            write(fd_tab[1], &num, 1); //wysyłanie na pipe
        }
        fclose(picture);*/
        write(1, "Czekam 5 sekund\n", 16);
        sleep(5);
        close(fd_tab[1]); /* Zakończenie pisania */
        wait(NULL);       /* Zaczekaj aż dziecko skończy */
        write(1, "rodzic konczy prace\n", 20);
        exit(EXIT_SUCCESS);
    }
    else if (pid == 0) //dziecko
    {
        close(fd_tab[1]); //zamykamy nieużywane pisanie
        close(0);         //zamknięcie deskryptora 0
        dup(fd_tab[0]);   //zduplikowanie potoku na deskryptor 0
        execlp("/usr/bin/display", "display", (char *)NULL);
        read(fd_tab[0], &num, 1);
        close(fd_tab[0]); //zamknij czytanie jak nie ma już nic
        exit(EXIT_SUCCESS);
    }
    else
    {
        write(2, "error przy forku\n", 17);
    }
    //KOMENTARZ
    //obrazek zostanie wyświetlony po zamknięciu potoku przez rodzica
}