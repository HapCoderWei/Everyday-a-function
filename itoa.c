#include <stdio.h>
#include <ctype.h>
#include <string.h>

void reverse(char s[])          /* reverse a string s */
{
    int i = 0, j;
    char c;
    j = strlen(s)-1;
    while(i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        ++i; --j;
    }
}
void my_itoa( int n, char s[] )
{
    int i, sign;
    if((sign=n)<0) {
        n = -n;
    }
    i = 0;
    do {
        s[i++] = n%10+'0';
    } while((n /= 10) > 0);     /* do-while get every charactor of n */
    if(sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';                /* Ensure s[i] is '\0' */
    reverse(s);                 /* cause s is reversed order, reverse s */
}
int main(int argc, char *argv[])
{
    int num;
    char s[10] = "abcdefghi";
    printf("Input a num: ");
    scanf("%d", &num);
    my_itoa(num, s);
    printf("The string of %d is %s\n", num, s);
    return 0;
}
