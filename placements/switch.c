#include<stdio.h>

int main()
{
	char ch;
	scanf("%c", &ch);
	while(ch<='F'){
		switch(ch){
			case'A':case'B':case'C':case'D':ch++;continue;
			case'E':case'F':ch++;
		}
		putchar(ch);
		scanf("%c", &ch);
	}
	printf("\n");
	return 0;
}
