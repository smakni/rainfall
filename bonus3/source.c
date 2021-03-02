#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char buffer1[66];
    char buffer2[65];
    int fd;

    fd = fopen("/home/user/end/.pass", "r");
    if (fd == NULL || argc != 2) {
        return 1;
    }
    fread(buffer1, 1, 66, fd);
    atoi(argv[1]);
    fread(buffer2, 1, 65, fd);
    fclose(fd);
    if (strcmp(buffer1, buffer2)) {
        execl("/bin/sh", "sh", NULL);
    }
    return 0;
}
