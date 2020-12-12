#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int mem_desc;
    mem_desc = open("memory2", O_RDWR, 0);
    if (mem_desc < 0)
    {
        mem_desc = open("memory2", O_RDWR | O_CREAT, 0);
    }

    int pid = fork();
    if (pid > 0) //rodzic
    {
        char file_name[100];
        int files_fd;
        int file_size;
        int tmp;
        int *addr = NULL;
        FILE *file_to_read;
        while (1)
        {
            printf("Podaj nazwe pliku: ");
            scanf("%s", file_name);
            files_fd = open(file_name, O_RDONLY, 0);
            if (files_fd > 0)
            {
                file_size = lseek(files_fd, 0, SEEK_END);
                ftruncate(mem_desc, file_size);
                addr = (int *)mmap(NULL, file_size, PROT_WRITE | PROT_READ, MAP_SHARED, mem_desc, 0);
                int i = 0;
                file_to_read = fopen(file_name, "r");
                while (!feof(file_to_read))
                {
                    if ((tmp = fgetc(file_to_read)) == NULL)
                        break;
                    addr[i++] = tmp;
                }
                msync(addr, file_size, MS_SYNC);
                munmap(addr, file_size);
            }
            else
            {
                printf("Niepoprawny plik.\n");
            }
            close(files_fd);
        }
        close(mem_desc);
        exit(EXIT_SUCCESS);
    }
    else if (pid == 0) //dziecko
    {
        execlp("display", "display", "-update", "1", "-delay", "2", "memory2", (char *)NULL);
    }
    else
    {
        write(2, "error przy forku\n", 17);
    }
    return 0;
}