#include <stdio.h>

/* This version always has a compiler warning. */
/* Cause the first parameter is a const char  */
/* pointer, but result type is a char pointer */
/* Either I use a const char pointer or a char */
/* pointer, it will get a warning. */
/* However it doesn't matter the finally result. */
char *my_strchr(const char *cs, int c)
{
    const char *ch;
    ch = cs;
    while( *ch != c && *ch != '\0') {
        ch++;
    }
    return (*ch == c)?ch:NULL;
}
int main(int argc, char *argv[])
{
    const char *str = "Try not. Do, or do not. There is no try.";
    char target = 'T';
    const char *result = str;

    while((result = my_strchr(result, target)) != NULL) {
        printf("Found '%c' starting at '%s'\n", target, result);
        ++result;
    }
    return 0;
}
