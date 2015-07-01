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

/* This a Dennis M. Ritchie Edition. I see it in  */
/* <<The C Programming Language>>(Second Edition) */
/* He didn't use head file <string.h>. */
char * Dennis_strcat(char *dest, const char *src)
{
    int i, j;
    i = j = 0;
    while(dest[i++] != '\0') { ++i; }
    while((dest[i++] = src[j++]) != '\0');
}
int main(int argc, char *argv[])
{
    char str[50] = "Hello ";
    char str2[50] = "World!";
    my_strcat(str, str2);
    my_strcat(str, " ...");
    my_strcat(str, " Goodbye World!");
    puts(str);

    char des[50] = "Hello ";
    char rit[50] = "World!";
    Dennis_strcat(des, rit);
    Dennis_strcat(des, " ...");
    Dennis_strcat(des, " Goodbye World!");
    puts(str);
    return 0;
}
