#include <stdio.h>

/* I can't understand the uses of this function from */
/* the standard manual. So I will describe it in my  */
/* words. This function return the charactar's index */
/* which is the first not occured in src string. */
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
    const char *string = "abcde312$#@";
    const char *low_alpha = "qwertyuiopasdfghjklzxcvbnm";

    size_t spnsz = my_strspn(string, low_alpha);
    printf("After skipping initial lowercase letters from '%s'\n"
        "The remainder is '%s'\n", string, string+spnsz);
    return 0;
}
