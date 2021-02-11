#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int run(){
	fwrite("Good... Wait what?\n", 1, 19, stdout);
	system("/bin/sh");
}

int main(int argc, char **argv)
{
 	char buffer[64];
	gets(buffer);
}