#include <iostream>
using namespace std;

int main()
{
	char ch,filename[50];
	cin >> filename;
	FILE *f=fopen(filename,"r");
	int  c1open=0,c1close=0;
	for( ch = fgetc(f) ; ch!=EOF ; ch=fgetc(f) )
	{
		if(ch=='"') 
			for( ch=fgetc(f) ,cout<<'"'; ch!=EOF && ch!='"' ;  )
			{
		//		if( ch!=' ' && ch!='\t' && ch!='\n')
					cout<<ch;
				ch=fgetc(f);
			}
		if(ch == '/')
		{
			ch = fgetc(f);
			if(ch == '/')
				for( ch=fgetc(f) ; ch!='\n' ; ch=fgetc(f) );
			else 
			{
				if(ch == '*')
				{
					c1open++;
					for( ch=fgetc(f) ; ch!=EOF ; ch=fgetc(f))
					{
						if(ch=='*')
						{
							ch=fgetc(f);
							if(ch=='/')
							{
								c1close++;
							//	if(c1open == c1close)
									break;
							}
						}
						if(ch=='/')
						{
							ch=fgetc(f);
							if(ch=='*')
								c1open++;
						}
					}
				}
				else //if(ch!=' ' && ch!='\t' && ch!='\n')
					cout << '/' << ch;
			}
		}
		else //if(ch!=' ' && ch!='\t' && ch!='\n')
			cout << ch;
	}
	return 0;	
}
