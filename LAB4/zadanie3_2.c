#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

int main()
{
    char name[100];
    char *fifo_name = "/home/emilia/Pulpit/fifo";
    char buffer2[200];
    int fd = open(fifo_name, O_RDONLY);
    if (fd == -1)
    {
        write(2, "Nie ma pliku lub nie można go odczytac\n", 40);
        exit(EXIT_FAILURE);
    }
    execlp("/usr/bin/tail", "tail -c +0 -f /home/emilia/Pulpit/fifo", (char *)NULL);
    /*
    while (read(fd, &buffer2, 200) > 0)
    {
        write(STDOUT_FILENO, "#", 1);
        write(STDOUT_FILENO, &buffer2, 200);
        write(STDOUT_FILENO, "#", 1);
        for (int i = 0; i < 200; i++)
        {
            buffer2[i] = '\0';
        }
    }
    close(fd); //zamknij czytanie jak nie ma już nic
    exit(EXIT_SUCCESS);
*/
    return 0;
}