#include <stdlib.h>
#include <stdio.h>

void n() {
    system("/bin/cat /home/user/level7/.pass");
}

void m() {
    puts("Nope");
}

int main(int argc, char const *argv[]) {
    char *buffer1 = malloc(64);
    char *buffer2 = malloc(4);

    strcpy(buffer1, argv[1]);
    return 0;
}
