#include <stdio.h>
#include <stdlib.h>

int m;

void o() {
    system("/bin/sh");
    exit(1);
}

void n() {
    char buffer[512];

    fgets(buffer, 512, stdin);
    printf(buffer);
    exit(1);
}

int main(int argc, char const *argv[])
{
    n();
}
