#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int files_fd;
    int file_size = 0;
    char *addr = NULL;
    int mem_desc;
    char file_name[100];

    mem_desc = open("memory", O_RDWR);
    addr = mmap(NULL, file_size, PROT_WRITE | PROT_READ, MAP_SHARED, mem_desc, 0);
    if (mem_desc < 0)
    {
        mem_desc = open("memory", O_RDWR | O_CREAT);
    }
    while (1)
    {
        printf("Podaj nazwe pliku: ");
        scanf("%s", file_name);
        files_fd = open(file_name, O_RDONLY);
        if (files_fd > 0)
        {
            file_size = lseek(files_fd, 0, SEEK_END);
            ftruncate(mem_desc, file_size);
            addr = mmap(NULL, file_size, PROT_WRITE | PROT_READ, MAP_SHARED, mem_desc, 0);
            read(files_fd, addr, file_size);
        }
        else
        {
            printf("Niepoprawny plik.\n");
        }
        close(files_fd);
    }
    munmap(addr, file_size);
    close(mem_desc);
    return 0;
}