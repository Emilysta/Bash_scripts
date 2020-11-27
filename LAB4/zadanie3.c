#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char *fifo_name = "/home/emilia/Pulpit/fifo";
    char name[100];
    int text_c[200];

    if (mkfifo(fifo_name, 0666) == -1)
    {
        write(2, "fifo utworzone lub nie da sie utworzyc\n", 39);
    } //nazwany potok
    if (argc > 1)
    {
        int fd = open(fifo_name, O_WRONLY);
        write(1, "elo2\n", 5);
        if (fd < 0)
        {
            write(2, "Nie ma pliku lub nie można go odczytac\n", 39);
            exit(EXIT_FAILURE);
        }
        for (int i = 1; i < argc; i++)
        {
            write(fd, "\nNowy plik:\n", 12);
            int fd_file = open(argv[i], O_RDONLY);
            if (fd_file < 0)
            {
                write(2, "Nie ma pliku lub nie można go odczytac\n", 39);
                write(1, "Pomijam plik: ", 14);
                write(1, name, sizeof(name));
            }
            else
            {
                while (read(fd_file, &text_c, 200) > 0)
                {                            //czytanie do końca pliku
                    write(fd, &text_c, 200); //wysyłanie na pipe
                    for (int i = 0; i < 200; i++)
                    {
                        text_c[i] = '\0';
                    }
                }
                close(fd_file);
            }
        }
        close(fd); /* Zakończenie pisania */
    }
    else
    {
        write(1, "Brak argumentow\n", 16);
        exit(EXIT_FAILURE);
    }
    write(1, "Czekam 5 sekund i koncze\n", 25);
    sleep(5);
    exit(EXIT_SUCCESS);

    return 0;
}