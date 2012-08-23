#include<stdio.h>
main()
{
	int n,m;
	scanf("%d",&n);
	m=n%10;
	n=n/10;
	switch(n)
      {
	    	case 1 :printf("X");break;
		case 2 :printf("XX");break;
		case 3 :printf("XXX");break;
		case 4 :printf("XL");break;
		case 5 :printf("L");break;
		case 6 :printf("LX");break;
		case 7 :printf("LXX");break;
		case 8 :printf("LXXX");break;
		case 9 :printf("XC");break;
		case 10 :printf("C");break;
      }
        switch(m)
      {	
	      	case 1 :printf("I\n");break;	
	      	case 2 :printf("II\n");break;
	      	case 3 :printf("III\n");break;
	      	case 4 :printf("IV\n");break;
	      	case 5 :printf("V\n");break;
	      	case 6 :printf("VI\n");break;
	      	case 7 :printf("VII\n");break;
	      	case 8 :printf("VIII\n");break;
	      	case 9 :printf("IX\n");break;
	      	case 10 :printf("X\n");break;
      }
		
		
		
}		
		
		
		
		
		


































		
