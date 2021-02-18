#include <stdio.h>

int main(int argc, char const *argv[]) {
    while (1) {
        char *auth = "";
        char *service = "";
        char *str = "%p, %p \n";
        printf(str, auth, service);
        fgets("", 128, stdin);
    }
}
