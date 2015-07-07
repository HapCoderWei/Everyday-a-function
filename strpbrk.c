#include <stdio.h>

char *my_strpbrk( const char* dest, const char* breakset )
{
    const char *d, *s;
    s = breakset;

    while(*s != '\0') {
        for(d = dest; *d != '\0' && *d != *s; d++)
        ;
        if(*d == *s) {
            return d;
        }
        s++;
    }
    return NULL;
}
size_t my_strspn( const char *dest, const char *src )
{
    size_t i, j;
    i = 0;
    while(dest[i] != '\0') {
        for(j = 0; src[j] != '\0' && src[j] != dest[i]; j++) /* Test if dest[i] is in the src */
        ;
        if(dest[i] != src[j]) {
            return i;
        }
        i++;
    }
    /* I really don't understand what is the return value */
    /* if the search failed. */
    return i;
}
int main(int argc, char *argv[])
{
    const char* str = "hello world, friend of mine!";
    const char* sep = " ,!";

    unsigned int cnt = 0;
    do{
        str = my_strpbrk(str, sep);         /* find separator */
        if(str) str += my_strspn(str, sep); /* skip separator */
        ++cnt;                              /* increment word count */
    } while (str && *str);
    printf("There are %d words\n", cnt);
    return 0;
}
