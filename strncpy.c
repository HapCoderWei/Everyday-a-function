#include <stdio.h>

char * my_strncpy(char *s, const char * ct, size_t n)
{
    int i = 0;
    while (ct[i] != '\0' && i < n) {
        s[i] = ct[i++];
    }
    if(i < n) {
        s[i++] = '\0';
    }
    s[i] = '\0';
    return s;
}
int main(int argc, char *argv[])
{
    char str[] = "Hello, world!";
    char copy[40] = {0};

    my_strncpy(copy, str, sizeof(copy) - 1);
    printf("%s\n", copy);

    my_strncpy(copy, str, 5);

    copy[5] = '\0';
    printf("%s\n",copy);
    return 0;
}
