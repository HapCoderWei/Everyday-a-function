#include <stdio.h>
#include <string.h>

void* my_memchr( const void* ptr, int ch, size_t count )
{
    unsigned char c = ch;
    size_t i;
    for(i = 0; i < count; i++) {
        if(*(unsigned char *)(ptr+i) == c) { return (void *)(ptr+i); }
    }
    return NULL;
}
int main(int argc, char *argv[])
{
    char str[] = "ABCDEFG";
    char *ps = my_memchr(str, 'D', strlen(str));
    if(ps != NULL) {
        printf("search character found: %s\n", ps);
    } else {
        printf("search character not found\n");
    }
    return 0;
}
