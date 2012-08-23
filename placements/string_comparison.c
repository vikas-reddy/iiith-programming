#include<stdio.h>

int main()
{
    char *p="String";
    char q[] = "String";
    char r[] = "String";
    int x=0;

    printf("%d\n", sizeof(q));

    if(p == "String")
    {
        printf("Pass 1");
        if(p[sizeof(p)-2]=='g')
            printf("Pass 2");
        else
            printf("Fail 2");
    }
    else
    {
        printf("Fail 1");
        if(p[sizeof(p)-2]=='g')
            printf("Pass 2");
        else
            printf("Fail 2");
    }

    printf("\n");
    return 0;
}
