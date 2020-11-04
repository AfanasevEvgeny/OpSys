#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    char buf[1000];
    int l = 0;
    while (read(STDIN_FILENO, &buf[l++], 1) > 0);
    printf("%s", buf);
    int file;
    if (argc == 2)
    {
        fclose(fopen("ex2.txt", "wb"));
        file = open(argv[1], O_WRONLY);
    }
    else if (argc == 3)
    {
        fclose(fopen("ex2.txt", "ab+"));
        file = open(argv[2], O_WRONLY | O_APPEND);
    }

    write(file, buf, l - 1);
    close(file);

    return 0;
}
