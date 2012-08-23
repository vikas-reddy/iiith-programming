#include<stdio.h>
#include<string.h>

int long_len=0;

void longest_palindrome(char *p, char *q)
{
    if(p > q)
        return;

    if(p == q)
    {
        long_len++;
        return;
    }

    if(*p == *q)
    {
        long_len += 2;
        longest_palindrome(p+1, q-1);
    }
    else
    {
        longest_palindrome(p+1, q);
        longest_palindrome(p, q-1);
    }
    return;
}

int main()
{
    char str[20];
    scanf("%s", str);

    longest_palindrome(str, str + strlen(str) - 1);

    printf("Length of longest palindrome is %d\n", long_len);
    return 0;
}
