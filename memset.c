#include <stdio.h>
#include <string.h>

void * my_memset_1( void* dest, int ch, size_t count)
{
    unsigned char c = ch;
    size_t i = 0;

    while(i < count) {
        *(unsigned char *)(dest+i) = c;
        ++i;
    }

    return dest;
}
void * my_memset_2( void* dest, int ch, size_t count )
{
    while(count > 0) {
        *(unsigned char *)(dest+count-1) = ch;
        --count;
    }
}
int main(int argc, char *argv[])
{
    char str[] = "ghghghghghghghghgh";
    char str1[] = "ghghghghghghghghgh";
    puts(str);
    my_memset_1(str, 'a', sizeof(str));
    //my_memset_2(str1, 'z', sizeof(str1));
    /* memset() didn't check if count is greater than sizeof(dest) */
    memset(str1, 'z', sizeof(str1)+2);
    puts(str);
    puts(str1);
    return 0;
}
