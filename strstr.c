#include <stdio.h>
#include <stdlib.h>

int *getNext( const char* str, int len)
{
    int i, k;
    int *next = (int *)malloc(sizeof(int)*len);
    next[0] = -1;
    i = 0; k = -1;
    while(i < len-1) {
        if(k == -1 || str[i] == str[k]) {
            if(str[++i] == str[++k]) {
                next[i] = next[k];
            }
            else {
                next[i] = k;
            }
        }
        else {
            k = next[k];
        }
    }
    return next;
}
char *my_strstr( const char* str, const char* substr )
{
    int i, j, strLen, subLen;
    int *next;
    if(substr == NULL) { return str; }

    /* get length of strings */
    for(strLen = 0; str[strLen] != '\0'; strLen++) ;
    for(subLen = 0; substr[subLen] != '\0'; subLen++) ;
    next = getNext(substr, subLen);

    i = 0; j = 0;
    while(i < strLen && j < subLen) {
        if(j == -1 || str[i] == substr[j]) {
            i++; j++;
        }
        else {                  /* KMP */
            j = next[j];
        }
    }
    free(next);
    if(j == subLen) {
        return str + i - j;
    }
    else {
        return NULL;
    }
}

/* ---------Test Function----------- */
void find_str(char const* str, char const* substr);
int main(int argc, char *argv[])
{
    char* str = "one two three";
    find_str(str, "two");
    find_str(str, "");
    find_str(str, "nine");
    find_str(str, "n");
    return 0;
}
void find_str(char const* str, char const* substr)
{
    char *pos = my_strstr(str, substr);
    if(pos) {
        printf("found the string '%s' in '%s' at position: %ld\n", substr, str, pos-str);
    }
    else {
        printf("the string '%s' was not found in '%s'\n", substr, str);
    }
}