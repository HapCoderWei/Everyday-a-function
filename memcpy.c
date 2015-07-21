#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void *my_memcpy( void *dest, const void *src, size_t count )
{
    size_t i;
    for(i = 0; i < count; i++) {
        /* void* is a good parameter, but a hard implement */
        *(int *)(dest+i) = *(int *)(src+i);
    }
    return dest;
}
int main(int argc, char *argv[])
{
    size_t n;
    char source[] = "once upon a midnight dreary...", dest[4];
    my_memcpy(dest, source, sizeof dest);
    for(n = 0; n < sizeof dest; ++n)
      putchar(dest[n]);

    /* reinterpreting data */
    int32_t m;
    double d = 0.1;
    my_memcpy(&m, &d, sizeof d); /* OK */
    printf("\n%a is %" PRIx32 " as an int32_t\n", d, n);
    return 0;
}
