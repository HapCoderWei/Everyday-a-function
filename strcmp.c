#include <stdio.h>
/* I won't use any functions in string.h file */
/* from now on, cause I'm writting the string lib */

int my_strcmp(const char *lhs, const char *rhs)
{
    int i;
    for (i = 0; lhs[i] == rhs[i] && rhs[i]!='\0'; i++)
    ;
    return lhs[i] - rhs[i];
}
int main(int argc, char *argv[])
{
    const char* string = "Hello World!";

    int a = my_strcmp(string, "Hello World!");
    if(a == 0) {
        printf("String are matching.\n");
    }

    int b = my_strcmp(string, "Hello");
    if(b >= 1) {
        printf("Left hand side is bigger than right hand side.\n");
    }

    int c = my_strcmp(string, "Hello there world!");
    if(c <= -1) {
        printf("Left hand side is smaller than right hand side.\n");
    }
    return 0;
}
