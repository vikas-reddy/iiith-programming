#include<stdio.h>
#include<string.h>

void recursive_string_reverse(char *p, char *q)
{
    if(p >= q)
        return;

    char temp;

    temp = *p;
    *p = *q;
    *q = temp;

    recursive_string_reverse(p+1, q-1);
}


int main()
{
	char string[20];
	int i=0, j=0, temp=0;

	printf("Enter the string to be reversed: ");
	scanf("%s", string);

	printf("Original String = %s\n", string);

    // Calling recursive function
    recursive_string_reverse(string, string + strlen(string) - 1);

	printf("Reversed String = %s\n", string);
    return 0;
    // END

	for(i=0, j=strlen(string)-1; i<=j; i++, j--)
	{
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
	}

	printf("Reversed String = %s\n", string);
	return 0;
}
