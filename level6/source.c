#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int(*t_func_ptr)(void) ;  //t_func_ptr >> void(*t_func_ptr)(void)

int n() {
    return system("/bin/cat /home/user/level7/.pass");
}

int m() {
    return puts("Nope");
}

int main(int argc, char const *argv[]) {
    char *buffer;
    t_func_ptr *fctptr;
    buffer = malloc(64);
    fctptr = malloc(4);
    *fctptr = &m;

    strcpy(buffer, argv[1]);
    (*fctptr)();
}
