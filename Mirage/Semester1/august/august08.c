#include<stdio.h>
main(){
FILE *f1,*f2;
int ch;
f1=fopen("s.c","r");
f2=fopen("08aug.c","w");
while(fscanf(f1,"%c",&ch)!=EOF)
fprintf(f2,"%c",ch);
}
