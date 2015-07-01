#include <stdio.h>
/* All I use the string.h head file is just for the */
/* strlen() function. */
#include <string.h>

char * my_strcat( char *dest, const char *src )
{
    int i, j;
    for (i = strlen(dest), j = 0; src[j] != '\0'; dest[i++] = src[j++]);
    /* This code snippet in comments under this line is another  \
       way to write this function */
    /* i = strlen(dest); */
    /* j = 0; */
    /* while(src[j] != '\0') { */
    /*     dest[i++] = src[j++]; */
    /* } */
    dest[i] = '\0';
    return dest;
}

int main(int argc, char *argv[])
{
    char str[50] = "Hello ";
    char str2[50] = "World!";
    my_strcat(str, str2);
    my_strcat(str, " ...");
    my_strcat(str, " Goodbye World!");
    puts(str);
    return 0;
}
