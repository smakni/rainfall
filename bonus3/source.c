#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char buffer1[66];
    char buffer2[65];
    FILE *fd;

    fd = fopen("/home/user/bonus3/.pass", "r");
    // fd = fopen("/home/user/end/.pass", "r");
    if (fd == NULL || argc != 2) {
        return 1;
    }
    fread(buffer1, 1, 66, fd);
    buffer1[atoi(argv[1])] = 0;
    fread(buffer2, 1, 65, fd);
    fclose(fd);
    if (strcmp(buffer1, argv[1]) == 0) {
        execl("/bin/sh", "sh", NULL);
    } else {
        puts("");
    }
    return 0;
}
