#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char name[100];
    if (argc <= 1)
    {
        write(1, "Nie podales nazwy pliku. Podaj ją teraz:\n", 42);
        char c;
        int j = 0;
        do
        {
            read(STDIN_FILENO, &c, 1);
            name[j] = c;
            j++;
        } while (c != '\n');
        name[j - 1] = '\0';
    }
    else
    {
        strcpy(name, argv[1]);
    }
    int fd_tab[2];
    int text_c[200];
    if (pipe(fd_tab) == -1)
    {
        write(2, "error przy tworzeniu pipe\n", 27);
        exit(EXIT_FAILURE);
    } //nienazwany potok

    int pid = fork();
    if (pid > 0)
    {                     //rodzic
        close(fd_tab[0]); /* Zamknięcie nieużywanego czytania */
        int fd = open(name, O_RDONLY);
        if (fd < 0)
        {
            write(2, "Nie ma pliku lub nie można go odczytac\n", 39);
            exit(EXIT_FAILURE);
        }
        while (read(fd, &text_c, 200) > 0)
        {                                   //czytanie do końca pliku
            write(fd_tab[1], &text_c, 200); //wysyłanie na pipe
            for (int i = 0; i < 200; i++)
            {
                text_c[i] = '\0';
            }
        }
        close(fd);
        write(1, "Czekam 5 sekund\n", 16);
        sleep(5);
        close(fd_tab[1]); /* Zakończenie pisania */
        exit(EXIT_SUCCESS);
    }
    else if (pid == 0)
    {                     //dziecko
        close(fd_tab[1]); //zamykamy nieużywane pisanie
        char buffer2[200];
        while (read(fd_tab[0], &buffer2, 200) > 0)
        {
            write(STDOUT_FILENO, "#", 1);
            write(STDOUT_FILENO, &buffer2, 200);
            write(STDOUT_FILENO, "#", 1);
            for (int i = 0; i < 200; i++)
            {
                buffer2[i] = '\0';
            }
        }
        close(fd_tab[0]); //zamknij czytanie jak nie ma już nic
        exit(EXIT_SUCCESS);
    }
    else
    {
        write(2, "error przy forku\n", 17);
    }
    return 0;
}