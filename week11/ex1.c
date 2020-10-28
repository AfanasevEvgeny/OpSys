#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>




int main() {
    int fd = open("ex1.txt", O_RDWR);  //open file in O_RDWR mode
    char string[] ="This is a nice day";
    //int length;
    struct stat file_stat;
    ftruncate(fd, strlen(string)); 
    stat("ex1.txt", &file_stat); //get stat of file ex1.txt

    char *file_addr = mmap(NULL, file_stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    memcpy(file_addr, string, strlen(string));
    msync(file_addr, strlen(string), MS_SYNC);
    munmap(file_addr, file_stat.st_size);
    close(fd);
    return 0;
}