#include<stdio.h>
#include<math.h>
// Simple Calculator

int isnum(char ch)
{
	if(ch>='0' && ch<='9')
		return 1;
	else
		return 0;
}

int main()
{
	char ch='\0';
	int N=0, state=0, answer=0, first_num=0, second_num=0, is_negative=0;
	// state = 0 --> no number is being scanned
	// state = 1 --> a number is being scanned
	for(;ch!=EOF;)
	{
		// going to the start of number
		for(ch=getchar(); !isnum(ch); ch=getchar()); 
		if(ch == '-')
			is_negative = 1;
		ch = getchar();
		N = (ch-'0');
		for(ch=getchar(); isnum(ch); N = N*10 + (ch-'0'), ch=getchar());
		first_num = N;
		if( is_negative == 1)
			first_num = -1 * N;

		// going to the start of number
		for(ch=getchar(); !isnum(ch); ch=getchar()); 
		if(ch == '-')
			is_negative = 1;
		ch = getchar();
		N = (ch-'0');
		for(ch=getchar(); isnum(ch); N = N*10 + (ch-'0'), ch=getchar());

		printf("%d\n",N);
	}
	/*for(ch=getchar(); ch != EOF; ch=getchar())
	{
		if(ch == '\n')
			printf("Answer = %d\n", answer);
		if( isnum(ch) )
		{
			if(state == 0)
			{
				N = int(ch-'0');
				state = 1;
			}
			else
			{
				N = N*10 + int(ch-'0');
			}
		}
	}*/
	return 0;
}
