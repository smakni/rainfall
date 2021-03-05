#include <string.h>
#include <stdio.h>
#include <unistd.h>

void p(char *dest, char *hyphen) {
    char buf[4096];
    puts(hyphen);
    read(0, buf, 4096);
    *strchr(buf, '\n') = '\0';
    strncpy(dest, buf, 20);
}

char *pp(char *ret) {
    char dest1[20];
    char dest2[20];
    p(dest1, "-");
    p(dest2, "-");
    strcpy(ret, dest1);
    ret[strlen(dest1)] = ' ';
    return (strcat(ret, dest2));
}

int main(int argc, char const *argv[])
{
    char ret[48];
    pp(ret);
    puts(ret);
    return (0);
}
