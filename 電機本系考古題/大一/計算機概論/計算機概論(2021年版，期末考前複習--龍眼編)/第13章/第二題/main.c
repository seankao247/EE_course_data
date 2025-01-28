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
            scanf("%s",&code);//讀取暗號
            strcpy(temp,code);//複製暗號
            for(j=0;j<strlen(code);j++)//大寫字母和數字分類
            {
                if((int)code[j]>=65&&(int)code[j]<=90)//大寫字母
                    check1++;
                if((int)code[j]>=48&&(int)code[j]<=57)//數字
                    check2++;
            }
            if(strlen(code)>10)
                printf("too long\n\n");//太長
            else if((check1==0&&check2!=0)||(check1!=0&&check2==0))//只有字母或只有數字
                printf("unrecognizeable!\n\n");//無法辨識
            else
            {
                for(j=0;j<strlen(temp);j++)//一個一個字元做切換
                {
                    if((int)code[j]<65&&(int)code[j-1]>=65)//如果這一位字元是大寫字母(>65)下一位字元是數字(<57)
                    {
                        for(k=b;k<j;k++)//在第j個字元的分析
                        {
                            a=(int)code[j]-48;//0的ASCII碼就是48，把字元變成真正的變數
                            code[k]+=a;
                            if((int)code[k]>90)//如果超過Z(90)，就馬上回歸成A(65)
                                code[k]-=26;
                        }
                        b=j;//跳過數字的部分，直接到下一個
                    }
                }
                printf("output:");
                for(j=0;j<strlen(temp);j++)//輸出印出來
                {
                    if((int)temp[j]>=65&&(int)temp[j]<=90)//如果是英文就印出來，不是就別印
                    printf("%c",code[j]);
                }
                printf("\n\n");
            }
        }
        printf("continue testing?  ");//最後詢問要不要繼續
        scanf("%d",&a);
        printf("\n");
        if(a==0)
            break;
    }
    return 0;
}