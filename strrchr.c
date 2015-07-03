#include <stdio.h>

/* This function also have a compiler warning */
/* I don't how to erase it.:-( */
char *my_strrchr( const char *str, int ch )
{
    const char *c;
    for(c = str; *c != '\0'; c++)
    ;
    while(*c != ch && c != str) {
        c--;
    }
    return (*c == ch)?c:NULL;
}
int main(int argc, char *argv[])
{
    char szSomeFileName[] = "foo/bar/foobar.txt";
    char *pLastSlash = my_strrchr(szSomeFileName, '/');
    char * pszBaseName = pLastSlash ? pLastSlash + 1 : szSomeFileName;
    printf("Base Name: %s", pszBaseName);
    return 0;
}
