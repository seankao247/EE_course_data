#include <stdio.h>
#include <stdlib.h>

void computer(int);
int max = 1000,min = 1;
int data,count=1;
int main()
{
    srand(time(NULL));
    data=rand()%1000+1;
    printf("�q����%d\n",data);
    for(;;)
    {
        int guess;
        printf("��%d�^�X\n",count);
        for(;;)
        {
            printf("�п�J%d��%d�������Ʀr:",min,max);
            scanf("%d",&guess);
            if(guess==data)
            {
                break;
            }
            else if((guess>=min)&&(guess<=max))
            {
                computer(guess);
                break;
            }
            else
            {
                printf("�A�O���O���ݪ�\n");
                printf("�Э��s��J�d�򤺪��Ʀr\n");
            }
        }
        if(guess==data)
        {
            printf("�F�A�ש�q��F\n");
            printf("�A��F%d�X�^�X",count);
            break;
        }
    }
    return 0;
}
void computer(int number)
{
    if((number>data)&&(number<=max))
    {
        printf("�Ӥj�F");
        max = number-1;
    }
    if((number<data)&&(number>=min))
    {
        printf("�j�p�F");
        min = number+1;
    }
    count++;
    printf("\n");
}
