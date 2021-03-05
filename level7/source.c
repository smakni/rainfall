#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char c[80];

struct test {
    int priority;
    char *str;
};

void m() {
    printf("%s - %d\n", c, (int)time(NULL));
}

int main(int argc, char const *argv[]){
    struct test *my_struct1, *my_struct2;
    my_struct1 = malloc(8);
    my_struct1->priority = 1;
    my_struct1->str = malloc(8);
    my_struct2 = malloc(8);
    my_struct2->priority = 2;
    my_struct2-> str = malloc(8);


    strcpy(my_struct1->str, argv[1]);
    strcpy(my_struct2->str, argv[2]);
    // FILE *fd = fopen("/home/user/level7/.pass", "r");
    FILE *fd = fopen("/home/user/level8/.pass", "r");
    fgets(c, 68, fd);
    puts("~~");
    return (0);
}
