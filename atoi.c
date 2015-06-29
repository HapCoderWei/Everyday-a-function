#include <stdio.h>
#include <ctype.h>
#include <string.h>

int my_atoi(char s[])
{
    int num, i, sign;
    for(i = 0; isspace(s[i]); ++i); /* ignore the space */
    sign = (s[i] == '-')?-1:1;      /* judge if number is negative */
    if(s[i] == '+' || s[i] == '-') {
        ++i;                    /* if number has a '+' or '-', ignore it */
    }
    for (num = 0; isdigit(s[i]); i++) {
        num = num*10 + (s[i] - '0'); /* convert string to number */
    }

    return sign*num;
}
int main(int argc, char *argv[])
{
    char s[20] = "";
    printf("Input a string number: ");
    scanf("%s", s);
    printf("String of %s is %d\n", s, my_atoi(s));
    return 0;
}
