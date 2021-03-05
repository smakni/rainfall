#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *auth = "";
char *service;

int main(int argc, char const *argv[]) {
    char buffer[128];
    while (1) {
        char *str = "%p, %p \n";
        printf(str, auth, service);
        printf("auth:%s\n", auth);
        printf("auth + 16:%s\n", auth + 16);
        printf("auth + 32:%c\n", auth[32]);
        if (fgets(buffer, 128, stdin) == NULL) {
            break ;
        }
        if (memcmp(buffer, "auth ", 5) == 0) {
            auth = malloc(4);
            if (strlen(buffer + 5) < 30) {
                strcpy(auth, buffer + 5);
            }
        }
        if (memcmp(buffer, "reset", 5) == 0) {
            free(auth);
        }
        if (memcmp(buffer, "service", 6) == 0) {
            service = strdup(buffer + 7);
        }
        if (memcmp(buffer, "login", 5) == 0) {
            if (auth[32] != 0) {
                system("/bin/sh");
            } else {
                fwrite("Password:\n", 1, 10, stdout);
            }
        }
    }
    return (0);
}
