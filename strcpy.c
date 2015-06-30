#include <stdio.h>

char * my_strcpy( char *s, const char *ct )
{
    int i;
    i = 0;
    while (ct[i] != '\0') {
        s[i] = ct[i++];
    }
    s[i] = '\0';
    return s;
}
int main(int argc, char *argv[])
{
    char A[] = "Take the test.";
    char B[50] = "";
    my_strcpy(B, A);
    A[0] = 'M';
    printf("A = %s\nB = %s\n", A, B);
    return 0;
}
