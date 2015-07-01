#include <stdio.h>
#include <string.h>

char *my_strncat( char *dest, const char *src, size_t count)
{
    size_t i, j;
    for(i=strlen(dest), j=0; src[j]!='\0' && j<count; dest[i++]=src[j++]);
    /* i = strlen(dest); */
    /* j = 0; */
    /* while(src[j] != '\0' && j < count) { */
    /*     dest[i++] = src[j++]; */
    /* } */
    dest[i] = '\0';
    return dest;
}
int main(int argc, char *argv[])
{
    char str[50] = "Hello World!";
    my_strncat(str, " Goodbye World!", 3);
    puts(str);
    return 0;
}
