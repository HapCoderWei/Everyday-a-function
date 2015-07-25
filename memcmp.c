#include <stdio.h>

int my_memcmp( const void* lhs, const void* rhs, size_t count )
{
    size_t i;
    i = 0;
    for(i = 0; i < count; i++) {
        if(*(unsigned char*)(lhs+i) != *(unsigned char*)(rhs+i)) {
            return *(unsigned char*)(lhs+i) - *(unsigned char*)(rhs+i);
        }
    }
    return 0;
}

void demo(const char* lhs, const char* rhs, size_t sz) {
    size_t n;
    for(n = 0; n < sz; ++n) putchar(lhs[n]);
    int rc = my_memcmp(lhs, rhs, sz);
    if (rc == 0) {
        printf(" compares equal to ");
    } else if (rc < 0) {
        printf(" precedes ");
    } else if(rc > 0){
        printf(" follows ");
    }
    for(n = 0; n < sz; ++n) putchar(rhs[n]);
    puts(" in lexicographical order");
}
int main(int argc, char *argv[])
{
    char a1[] = {'a', 'b', 'c'};
    char a2[sizeof(a1)] = {'a', 'b', 'd'};
    demo(a1, a2, sizeof a1);
    demo(a2, a1, sizeof a1);
    demo(a1, a1, sizeof a1);
    return 0;
}
