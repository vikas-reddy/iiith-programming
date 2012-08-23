#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short int rsearch(char *regex, char *str) {
    int len_regex = strlen(regex), len_str = strlen(str);
    short int ans = 0;
    int i = 0, j = 0;
    while(1) {
        if(str[i] == '\0') {
            break;
        }
        for(i = 0; (i < len_regex - 1) && (); i++) {

        }
    }
}

int main() {
    char str[20], regex[20];

    printf("Regular Expression (only ? and * are supported): "); scanf("%s", regex);
    printf("String: "); scanf("%s", str);

    printf("Matches? : %d\n", rsearch(regex, str));
}
