#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef void(*t_func_ptr)(void);

int n() {
    return system("/bin/cat /home/user/level7/.pass");
}

int m() {
    return puts("Nope");
}

int main(int argc, char const *argv[]) {
    char *buffer = malloc(64);
    t_func_ptr *func;
    func = malloc(4);
    *func = (void *)m;

    strcpy(buffer, argv[1]);
    (**func)();
}
