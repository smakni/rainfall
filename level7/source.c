#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char c[80];

void m() {
    printf("%s - %d\n", c, (int)time(NULL));
}

int main(int argc, char const *argv[]){
    char *ptr1 = malloc(8);
    ptr1 = malloc(8);
    char *ptr2 =  malloc(8);
    ptr2 =  malloc(8);
    strcpy(ptr1, argv[1]);
    strcpy(ptr2, argv[2]);
    FILE *fd = fopen("/home/user/level7/.pass", "r");
    // FILE *fd = fopen("/home/user/level8/.pass", "r");
    // FILE *fd = fopen("./flag", "r");
    fgets(c, 68, fd);
    puts("~~");
    return (0);
}
