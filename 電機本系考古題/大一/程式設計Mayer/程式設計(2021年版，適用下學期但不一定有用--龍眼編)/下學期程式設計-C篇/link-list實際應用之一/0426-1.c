#include <stdio.h>
#include <stdlib.h>
//�����k����ѩݪ����k
typedef struct model
{
    int number;
    char name[20];
    struct model* next;
}model;//�Хߤ@���c
int main()
{
    int N,count=0;
    model* a,* first,* later;
    for(;;)/*1.��ܭ���2.��ܲĤG���ΥH�W*/
    {
        printf("�п�J�Ʀr : ");
        scanf("%d",&N);//Ū�Ʀr
        if(N==0)break;//��J0�N���X�h
        a=(model* )malloc(sizeof(model));//1.��O����n�@��model�j�p�����c(a���V�o�ӵ��c)2.a���V�s���c,�ª��_��
        a->number=N;
        printf("�п�J�W�r : ");
        scanf("%s",a->name);
        if(count==0) first=a;//�p�Ga���V�Ĥ@�ӵ��c,�hfirst�]���V�o�Ĥ@�ӵ��c
        else later->next=a;//�쥻���VNULL�ܦ����V�U�@�ӵ��c(a)
        a->next=NULL;//�w�]a���V�����c�̭������ЬO�ū���
        later=a;//1.later�]���V�ثea���V������,�]���ݷ|�j���a���з|���V�O�B2.�e�@�ӵ��c��next�w�g�M�U�@�ӳs�_�ӤF
        count++;                                                                                           //�ҥHlater���V�U�@�ӵ��c,�M�W�@�ӵ��c����
    }
    a=first;
    printf("\n���� : ");
    while(a!=NULL)
    {
        printf("(%d,%s)-->",a->number,a->name);
        a=a->next;
    }
    printf("THE END");
    return 0;
}
