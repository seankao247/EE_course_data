#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a,i,j,k;
    char code[20],temp[20];
    while(1)
    {
        for(i=0;i<3;i++)
        {
            int b=0,check1=0,check2=0;
            printf("input:");
            scanf("%s",&code);//Ū���t��
            strcpy(temp,code);//�ƻs�t��
            for(j=0;j<strlen(code);j++)//�j�g�r���M�Ʀr����
            {
                if((int)code[j]>=65&&(int)code[j]<=90)//�j�g�r��
                    check1++;
                if((int)code[j]>=48&&(int)code[j]<=57)//�Ʀr
                    check2++;
            }
            if(strlen(code)>10)
                printf("too long\n\n");//�Ӫ�
            else if((check1==0&&check2!=0)||(check1!=0&&check2==0))//�u���r���Υu���Ʀr
                printf("unrecognizeable!\n\n");//�L�k����
            else
            {
                for(j=0;j<strlen(temp);j++)//�@�Ӥ@�Ӧr��������
                {
                    if((int)code[j]<65&&(int)code[j-1]>=65)//�p�G�o�@��r���O�j�g�r��(>65)�U�@��r���O�Ʀr(<57)
                    {
                        for(k=b;k<j;k++)//�b��j�Ӧr�������R
                        {
                            a=(int)code[j]-48;//0��ASCII�X�N�O48�A��r���ܦ��u�����ܼ�
                            code[k]+=a;
                            if((int)code[k]>90)//�p�G�W�LZ(90)�A�N���W�^�k��A(65)
                                code[k]-=26;
                        }
                        b=j;//���L�Ʀr�������A������U�@��
                    }
                }
                printf("output:");
                for(j=0;j<strlen(temp);j++)//��X�L�X��
                {
                    if((int)temp[j]>=65&&(int)temp[j]<=90)//�p�G�O�^��N�L�X�ӡA���O�N�O�L
                    printf("%c",code[j]);
                }
                printf("\n\n");
            }
        }
        printf("continue testing?  ");//�̫�߰ݭn���n�~��
        scanf("%d",&a);
        printf("\n");
        if(a==0)
            break;
    }
    return 0;
}