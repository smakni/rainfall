#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buf[40];
    int nb;

    nb = atoi(argv[1]);
    if (nb > 9) {
        return (1);
    }
    nb *= 4;
    memcpy(buf, argv[2], nb);
    if (nb == 0x574f4c46) {
        execl("/bin/sh", "sh", NULL);
    }
    return 0;
}
