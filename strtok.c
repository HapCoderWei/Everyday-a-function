#include <stdio.h>

char *my_strtok( char *str, const char *delim )
{
    static int ret;             /* record return index */
    static int length;          /* record str's length to avoid overflow */
    static char *static_str;    /* record str's address when str is NULL */
    if(str == NULL) {           /* after first call */
        for(; static_str[ret] != '\0' && ret < length; ret++);
        if(ret == length) { return NULL; } /* if finished match, return NULL */
        else { ret++; return static_str+ret; } /* else return next non-null string */
    }
    else {                      /* when first times call */
        int i, j, delim_len;
        ret = 0; static_str = str; /* initial the static variables */
        for(length = 0; str[length] != '\0'; length++);
        for(delim_len = 0; delim[delim_len] != '\0'; delim_len++);

        for (i = 0; i < length; i++) { /* find every token and take the delimiter to '\0' */
            for (j = 0; j < delim_len; j++) {
                if(str[i] == delim[j]) {
                    str[i] = '\0';
                    break;
                }
            }
        }
        return str;
    }
}
int main(int argc, char *argv[])
{
    char input[] = "A bird   came down the walk";
    printf("Parsing the input string '%s'\n", input);
    char *token = my_strtok(input, " ");
    while(token) {
        puts(token);
        token = my_strtok(NULL, " ");
    }

    printf("Contents of the input string now: '");
    size_t n;
    for(n = 0; n < sizeof input; ++n) {
        input[n] ? printf("%c", input[n]) : printf("\\0");
    }
    puts("'");
    return 0;
}
