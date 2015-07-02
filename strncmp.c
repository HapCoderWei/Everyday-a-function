#include <stdio.h>
#include <string.h>
/* include string for main function uses strlen */

int my_strncmp(const char *lhs, const char * rhs, size_t count)
{
    int i;
    for(i = 0; lhs[i]==rhs[i]&&rhs[i]!='\0'&&i<count; i++)
    ;
    if(i == count) {
        return 0;
    }
    else {
        return lhs[i]-rhs[i];
    }
}
int main(int argc, char *argv[])
{
    const char *string = "Hello World!";
    const int size = strlen(string);

    int a = my_strncmp(string, "Hello World!", 5);
    if(a == 0) {
        printf("The 5 first char of each string are matching.\n");
    }

    int b = my_strncmp(string, "Hello", size);
    if(b >= 1) {
        printf("Left hand side is bigger than right hand side.\n");
    }

    int c = my_strncmp(string, "Hello there world!", size);
    if(c <= -1) {
        printf("Left hand side is smaller than right hand side.\n");
    }
    return 0;
}
