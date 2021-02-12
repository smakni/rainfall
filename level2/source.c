#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *p() {
    char buf[64];
    unsigned int address;

    fflush(stdout);

    gets(buf);

    address = __builtin_return_address(0);

    if ((address & 0xb0000000) == 0xb0000000) {
        printf("(%p)\n", address);
        exit(1);
    }

    puts(buf);

    return strdup(buf);
}

int main(int argc, char const *argv[]) {
    p();
}