#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5]={0,0,0,0,0};                   /*�x�s�ƾڪ��}�C*/
    int k,i,PASS,x,ii;
    int j = 0;                              /*i�Mii���O�j��*/
    int J = 1;                              /*PASS�O�z��j��A�@���j���i��@�����㪺bubble sort*/
                                            /*J�O�P�_�Y�ơA�Y�Ӧ��z��j��S�i�����bubble sort�A�hJ=1*/
    printf("�п�J���Ӽƾ� :\n");
    scanf("%4d %4d %4d %4d %4d",&a[0],&a[1],&a[2],&a[3],&a[4]);
    printf("�쥻�ƾڪ����� :\n");
    for(k = 0;k < 5;k++)
    {
        printf("%4d",a[k]);
    }
    for(PASS =0;PASS < 5 ;PASS++)          /*�z��j��*/
    {
        for(i = 0;i < 4;i++)                /*�z��j��̪�bubble sort*/
        {
            if(a[i]>a[i + 1])
            {
                x = a[i];
                a[i] = a[i + 1];
                a[i + 1] = x;
                j = 1;
            }
        }
        if((j == 1)&&(PASS < 4))             /*�p�G���i��bubble sort(j=1)�A�h��ܸg�L�z��X��*/
        {
            printf("\n�g�L��%d���z�� :\n",J);  /*J���]�w��1*/
            for(ii = 0;ii < 5-PASS;ii++)
            {
                printf("%4d",a[ii]);
            }
            J++;                             /*���z��~�|��J�[1*/
            j = 0 ;                          /*j�k�s*/
        }
        else if(PASS == 4)                   /*�p�G�O�̫�@���z��A�h����ܸg�L�z��X��*/
        {
            printf("\n�z���᪺���T���� :\n");
            for(ii = 0;ii < 5;ii++)
            {
                printf("%4d",a[ii]);
            }
            j = 0 ;
        }
        else                                /*�p�G�S���i��bubble sort�A�h�����i��U�@�����z��j��*/
        {
            j = 0 ;

        }
    }
    return 0;
}
