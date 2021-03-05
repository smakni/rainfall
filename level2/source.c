#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *p() {
    char buf[64];
	void *address;

    fflush(stdout);

    gets(buf);

    address = __builtin_return_address(0);

    if (((unsigned int)address & 0xb0000000) == 0xb0000000) {
        printf("(%p)\n", address);
        exit(1);
    }

    puts(buf);

    return strdup(buf);
}

int main(int argc, char const *argv[]) {
    p();
}