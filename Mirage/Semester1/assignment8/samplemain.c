#include "mylist.h"

main()
{
        int a[10]={1,2,3,4,5,6,7,8,9,10},i=0;
        node *start,*cur;
        start=malloc(sizeof(node *));
        start->data=a[i];
        start->next=NULL;
        cur=start;
        i++;
        while(i<10) {
                cur->next=malloc(sizeof(node *));
                cur=cur->next;
                cur->next=NULL;
                cur->data=a[i];
                i++;
        }
        print(start);
        printf("\n");
        start=recReverse(NULL,start);
        print(start);
        printf("\n");
        start=reverse(start);
        print(start);
        printf("\n");
}
