#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct fuck
{
    char A[1];
    struct fuck* next;
}fuck;
int main()
{
    int choice,count=1;
    fuck* a,* first,* b;
    while(1)
    {
        printf("1.Input \n2.Delete \n3.Leave \n4.Clean the window and show the row\nYour choice :");
        scanf("%d",&choice);
        if(choice==1)
        {
            a=(fuck* )malloc(sizeof(fuck));
            printf("What alphabet you want to input ?");
            scanf("%s",a->A);
            if(count==1)
            {
                first=a;
            }
            else if(count>1)
            {
                b->next=a;
            }
            a->next=NULL;
            b=a;
            count++;
        }
        a=first;
        if(choice==2)
        {
            char kill[1];
            fuck* killer,* nurse;
            printf("What alphabet you want to delete ?");
            scanf("%s",kill);
            if(strcmp(kill,(a->A))==0)//幹掉第一個
            {
                if(a->next==NULL)
                    {
                        printf("Nothing\n\n");
                        continue;
                    }
                    else
                    {
                        killer=a;
                        first=a->next;
                        free(killer);
                    }
            }
            else
            {
                while(strcmp(kill,(a->A))!=0)
                {
                    nurse=a;
                    a=a->next;
                }
                killer=a;
                nurse->next=a->next;
                free(killer);
            }
        }
        a=first;
        if(choice==3) break;
        if(choice==4) system("cls");
        printf("\nRow: ");
        while(a->next!=NULL)
        {
            printf("%s->",a->A);
            a=a->next;
        }
        printf("%s->NULL\n\n",a->A);
    }
    return 0;
}
