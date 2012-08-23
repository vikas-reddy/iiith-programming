#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int n;
	struct node *next;
};
struct node *insert(struct node *start,int N)
{
	struct node *new,*ptr;
	new=(struct node *)malloc(sizeof(struct node));
	new->n=N;
	ptr=start;
	if(ptr==NULL) 
	{
		new->next=NULL;
		start=new;
		return start;
	}
	if(ptr->n > N) 
	{
		new->next = ptr;
		start=new;
		return start;
	}
	for(  ;ptr->next!=NULL  &&  ptr->next->n < N;  ptr=ptr->next );
	if(ptr->n  <  N)
	{
		new->next = ptr->next;
		ptr->next= new;
	}
	return start;
}
struct node *del(struct node *start)
{
	struct node *temp;
	for(;start;)
	{
		temp=start->next;
		free(start);
		start=temp;
	}
	return start;

}
struct node *rem(struct node *start,int N)
{
	struct node *ptr,*temp=start;
        if(start==NULL) return start;
	if(start->n==N)  
	{
		start=start->next;
		free(temp);
		return start;
	}
	for( ;temp->next->n != N; temp=temp->next);
	ptr=temp->next;
	temp->next=temp->next->next;
	free(ptr);
	return start;
}
void print(struct node *start)
{
	if(start==NULL) return;
	struct node *temp=start;
	for(  ; temp ; printf("%d ",temp->n),temp=temp->next );
	printf("\n");
}
main()
{
	int i=0,m=0,X=0,I=0,D=0,P=0,R=0,N=0,n=0;
	char a[200];
	scanf("%[^\n]",a);
	struct node * start;
	start=NULL;
	for(i=0 ; a[i]!='\n' ; i++)
	{
		switch(a[i])
		{
			case'0':case'1':case'2':case'3':case'4':
			case'5':case'6':case'7':case'8':case'9':
				n=n*10+a[i]-'0';
				N=1;
				break;
			case'-':  m=1;  break;
			case'I':I=1;N=0;break;
			case'P':P=1;N=0;break;
			case'R':R=1;N=0;break;
			case'D':D=1;N=0;break;
			case'X':X=1;N=0;exit(0);break;
			case' ':case'\t':
				if(m)        {  m=0;                    n = (-1)*n;     }
				if(I && N )  {  start=insert(start,n);  n=0; I=0; N=0;  }	
				if(R && N )  {  start=rem(start,n);  	n=0; R=0; N=0;  }
				if(   D   )  {  start=del(start);      	n=0; D=0; N=0;  }
				if(   P   )  {  print(start);           n=0; P=0; N=0;  }
				        break;
		}
	}
}	


