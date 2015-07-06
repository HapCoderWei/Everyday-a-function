#include <stdio.h>
#include <string.h>

/* The opposite of strspn function */
size_t my_strcspn( const char *dest, const char *src )
{
    size_t i, j;
    i = 0;
    while(dest[i] != '\0') {
        for(j = 0; src[j] != '\0' && dest[i] != src[j]; j++)
        ;
        if(dest[i] == src[j]) {
            return i;
        }
        i++;
    }
    return i;
}

int main(int argc, char *argv[])
{
    const char *string = "abcde312$#@";
    const char *invalid = "*$#";

    size_t valid_len = my_strcspn(string ,invalid);
    if(valid_len != strlen(string)) {
        printf("'%s' contains invalid chars starting aa position %zu\n",
            string, valid_len);
    }
    return 0;
}
