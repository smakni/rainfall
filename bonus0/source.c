#include <string.h>
#include <stdio.h>
#include <unistd.h>

void p(char *dest, char *hyphen) {
    char buf[4096];
    puts(hyphen);
    read(0, buf, 4096);
    int index = strchr(buf, '\n') - buf;
    buf[index] = '\0';
    strncpy(dest, buf, 20);
}

void pp(char *ret) {
    char dest2[20];
    char dest1[20];
    int len;
    p(dest1, " - ");
    p(dest2, " - ");
    strcpy(ret, dest1);
    len = strlen(ret);
    ret[len] = ' ';
    ret[len + 1] = '\0';
    strcat(ret, dest2);
    return;
}

int main(int argc, char const *argv[])
{
    char ret[42];
    pp(ret);
    puts(ret);
    return (0);
}
