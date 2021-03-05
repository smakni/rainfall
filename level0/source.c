#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    gid_t gid;
    uid_t uid;
    int number = atoi(argv[1]);

    if (number == 423) {
        char *hack[] = {strdup("/bin/sh"), NULL};
        gid = getegid();
        uid = geteuid();
        setresgid(gid, gid);
        setresuid(uid, uid);
        execv("/bin/sh", hack);
    } else {
        fwrite("No !\n", 5, 1, stderr);
        return 0;
    }
}
