#include <stdio.h>
#include <stdlib.h>

void *my_memmove( void *dest, const void *src, size_t count )
{
    size_t i;
    unsigned char *temp = NULL;
    temp = (unsigned char *)malloc(count + 1);
    for (i = 0; i < count; temp[i] = (*(unsigned char *)(src+i)), i++)
    ;
    for (i = 0; i < count; *(unsigned char *)(dest+i) = temp[i], i++)
    ;
    free(temp);
    return dest;
}
int main(int argc, char *argv[])
{
    char str[] = "1234567890";
    puts(str);
    my_memmove(str+4, str+3, 3);
    puts(str);
    return 0;
}
