#include <string.h>
#include <stdio.h>
#include <unistd.h>

void p(char *dest, char *useless) {
    char buf[4096];
    puts(useless);
    read(0, buf, 4096);
    *strchr(buf, '\n') = '\0';
    strncpy(dest, buf, 20);
}

char *pp(char *dest) {
    char dest1[20];
    p(dest1, "-");
    p(dest, "-");
    return "";
}

int main(int argc, char const *argv[])
{
    char *ret;
    char dest[20];
    ret = pp(dest);
    puts(ret);
    return (0);
}
