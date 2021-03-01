#include <string.h>
#include <stdlib.h>
#include <stdio.h>

enum {
    LANG_ENGLISH,
    LANG_FINNISH,
    LANG_NETHERLANDER,
};

int language = 0;

struct UserRecord{
	char name[40];
	char password[32];
};

void greetuser(struct UserRecord user) {
    char greeting[88];
    switch (language) {
        case LANG_FINNISH:
            strcpy(greeting, "Hyvää päivää ");
            break;
        case LANG_NETHERLANDER:
            strcpy(greeting, "Goedemiddag! ");
            break;
        default:
            strcpy(greeting, "Hello ");
            break;
    }
    strcat(greeting, user.name);
    puts(greeting);
}

int main(int argc, char const *argv[], char **env)
{
    struct UserRecord user = {0};

    if (argc != 3) {
        return (1);
    }

    strncpy(user.name, argv[1], sizeof(user.name));
    strncpy(user.password, argv[2], sizeof(user.password));

    char *envlang = getenv("LANG");
    if (envlang) {
        if (memcmp(envlang, "fi", 2)) {
            language = LANG_FINNISH;
        }
        if (memcmp(envlang, "nl", 2)) {
            language = LANG_NETHERLANDER;
        }
    }
    greetuser(user);
}
