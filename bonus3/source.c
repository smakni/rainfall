#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char buffer[66];
    int fd;

    fd = fopen("/home/user/end/.pass", "r");
    if (fd == NULL || argc != 2) {
        return 1;
    }
    fread(buffer, 1, 66, fd);
    atoi(argv[1]);
    fread(buffer, 1, 65, fd);
    fclose(fd);
    return 0;
}
