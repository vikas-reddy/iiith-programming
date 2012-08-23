#include<stdio.h>
struct studentdata
{
	char name[100];
	int rollno;
	int CGPA;
	char Hometown[100];
	char DOB[100];
};
main()
{
	struct studentdata stu1;
	printf("Enter the data\n");
	scanf("%[^\n]",stu1.name);
	scanf("%d",&stu1.rollno);
	scanf("%d",&stu1.CGPA);
	scanf("%s",stu1.Hometown);
	scanf("%s",stu1.DOB);
	
	printf("Entries are\n");
	printf("%s\n",stu1.name);
	printf("%d\n",stu1.rollno);
	printf("%d\n",stu1.CGPA);
	printf("%s\n",stu1.Hometown);
	printf("%s\n",stu1.DOB);
}

