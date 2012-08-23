#include<stdlib.h>
#include<stdio.h>
struct batsmandata
{
	char name[100];
	int runs;
	int innings;
};
main()
{
	struct batsmandata a[10];
	int n,i=0,max=0,index,j,k,m;
	while(1)
	{
		scanf("%d",&n);
		switch (n)
		{
			case 1 :  printf("Enter the new entry\n");
				  scanf("%s", a[i].name);
				  scanf("%d",& a[i].runs);
				  scanf("%d",& a[i].innings);
				  i++;
				  break;
			case 2 :  printf("Enter the entry to be deleted\n");
				  scanf("%d",&m);
				  break;
			case 3 : for(k=0 ; k<i ; k++)
					 if(k!=m-1) 
						 printf("%s\n%d\n%d\n",a[k].name,a[k].runs,a[k].innings);
				 exit(0);
				 break;
			
			case 4 :for(k=0,max=0 ; k<i ; k++)
					{
						if(max<a[k].runs)  
						{
							max=a[k].runs;
							index=k;
						}
					}
				printf("Player who scored max runs is\n%s\n%d\n%d\n",a[index].name,a[index].runs,a[index].innings);
				exit(0);
			/*case 5 :printf("Sorted list is\n"); 
				for(g=0 ; g<i ; g++)
					 for(h=g+1 ; h<i ; h++)
					 {
						if( a[g].runs < a[h].runs )
						{*/
							
			default :  printf("Not a valid input "); 
				   exit(0); 				
		}
	}
}




		
