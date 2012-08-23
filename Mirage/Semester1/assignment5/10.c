#include<stdio.h>
#include<math.h>
main()
{
	int i,k=0,s=1,p=0,m=0,q=0;
	float b[20],N=0,sum=0,j=10;
	char ch,a[50];
  	scanf("%[^\n]",a);
	for(i=0; a[i]!='\0';i++)
	{
		switch(a[i])
		{
			case '0':case '1':case '2':case '3':case '4':
			case '5':case '6':case '7':case '8':case '9':
				
				if(s==1)  N=N*10+(a[i]-'0');
				else if(s==2) { N=N+(a[i]-'0')/j;  j=j*10;}
				q=1;break;
			case '.':   s=2;   break;
			case '+': if(p!=1) 
				   {	if(m==1) {b[k]=-N;k++;}  
				 	else     {b[k]=N; k++; }
				   }
				  else if(q==1){if(m==1) {b[k]=-N;k++;}
					   else {b[k]=N;k++;}
				      q=0; }
				   N=0;j=10; s=1; m=0; p=0;
				   break;
			case '-':if(p!=1)  
				 {      if(m==1) {b[k]=-N;k++;}  
				  	else     {b[k]=N;k++;} 
				 }
				 else if(q==1){if(m==1) {b[k]=-N;k++;}
					   else {b[k]=N;k++;}
				      q=0; }
				 j=10;N=0;s=1;p=0;m=1;    
				 break;
			case 'e': if(m==1) {b[k]=-N;k++;}  
				  else     {if(i==0) {b[k]=1;k++;}
				  	    else {b[k]=N;k++;}
				  	   }
				  b[k]='e';k++;
				  p=1;N=0;j=10;s=1;m=0;q=0;
				  break;
			default : break;
		}
	}
	 if(m==1) {b[k]=-N;k++;}  
       	 else     {b[k]=N;k++; }
         for(i=0;i<k;i++)
	 {  if(b[i]=='e' && b[i+1]!='e')
	    {  sum=sum+b[i-1]*pow(10,b[i+1]);  sum=sum-b[i-1]; i++; }
	    else sum=sum+b[i];
	 }
	 printf("%.2f\n",sum);
}
