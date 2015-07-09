#include <stdio.h>

size_t my_strlen( const char *str )
{
    size_t len;
    for (len = 0; str[len] != 0; len++)
    ;
    return len;
}
int main(int argc, char *argv[])
{
    const char str[] = "How many characters does this string contain?";

    printf("without null character: %zu\n", my_strlen(str));
    printf("with null character: %zu\n", sizeof(str));
    return 0;
}
