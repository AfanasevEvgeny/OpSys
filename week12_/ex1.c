#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    int link = open("/dev/random", "r");
    char data[20];
    read(link, data, sizeof data);
    close(link);

    FILE *file = fopen("ex1.txt", "w");
    fprintf(file, "%s", data);
    fclose(file);
    return 0;
}