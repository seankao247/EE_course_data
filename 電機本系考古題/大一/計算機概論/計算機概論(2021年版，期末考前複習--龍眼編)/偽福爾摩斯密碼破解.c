#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char code[10];
    int check1=0,check2=0,check3=0;//check1�ˬd�j�g�r��,check2�ˬd�Ʀr,check3���ѤU����
    int i,j=0,k=0;//i�O�ˬd�r��j��,j�O��Ӧr��̪��S�w�r���i����R���j��,k�O�p�G�����Ш�2�ӭ^��r���H�W���޿�j��
    scanf("%s",code);
    for(i = 0 ;i <10;i++)
    {
        if((code[i]>=65)&&(code[i]<=90))//capital letter(�j�g�r��)
        {
            check1++;//(�O�j�g�r���N check1 �[�@)
        }
        else if((code[i]>=48)&&(code[i]<=57))//number(�Ʀr)
        {
            check2++;//(�O�Ʀr�N check2 �[�@)
        }
        else if(code[i]!=0)//neither capital letter nor small letter(�J���O�j�g�r���]���O�Ʀr)
        {
            check3++;//(��̳����O check3 �N�[�@)
        }
    }
    if(strlen(code)>10)//the amount of the string is larger than 10(�r��W�L10)
    {
        printf("Too long.");//�Ӫ��F
    }
    else if(((check1== 0)&&(check2 != 0))||((check1 !=0)&&(check2 == 0))||(check3 != 0))//1.all are capital letter or number 2.one of the string is neither capital letter nor small letter
    {
        printf("Unrecognizable.");//(�L�k����)
    }
    else//(�ŦX����N����)
    {
        for(j=0;j<strlen(code);j++)//(�r�꦳�h�ִN���h��)
        {
            if((code[j]<65)&&(code[j-1]>=65))//the last character is letter ,and the current one is number(��j-1�r���O�r���A�Ӳ�j�r���O�Ʀr)
            {
                for(k;k<j;k++)//(k��l�Ȭ�0)//�i��j��A���ഫ�r�����j-1�Ӧr���N���U�ӡA
                {
                    code[k]=code[k]+(code[j]-48);//�r���[�W�Ʀr
                    if(code[k]>90)//�W�LZ�N���^A�~�򭫷s��
                    {
                        code[k]=code[k]-26;
                    }
                }
                k=j;//
            }
        }
        printf("\n\n");
        for(i=0;i<strlen(code);i++)
        {
            if(code[i]>=65)
            {
                printf("%c",code[i]);
            }
        }
    }
    return 0;
}
