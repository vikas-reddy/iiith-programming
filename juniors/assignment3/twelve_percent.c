#include<stdio.h>
#include<math.h>

int main()
{
	char ch='\0';
	int i=0, state=0;
	float num=0;
	
	for(; ch!=EOF; ch=getchar())
	{
		for( ; ch<'0' && ch>'9'; printf("%c",ch), ch=getchar());
		for( ; (ch>='0' && ch<='9') || ch=='.'; ch=getchar())
		{
			printf("ENTERED\n");
			if( ch == '.' )
				state = 1;
			if(state == 0)
				num = num*10 + ch-'0';
		}
		printf("%d", num);
	}
	return 0;
}
