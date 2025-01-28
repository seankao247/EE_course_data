#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char code[10];
    int check1=0,check2=0,check3=0;//check1檢查大寫字母,check2檢查數字,check3為剩下部分
    int i,j=0,k=0;//i是檢查字串迴路,j是對該字串裡的特定字元進行分析的迴路,k是如果有重覆到2個英文字母以上的邏輯迴路
    scanf("%s",code);
    for(i = 0 ;i <10;i++)
    {
        if((code[i]>=65)&&(code[i]<=90))//capital letter(大寫字母)
        {
            check1++;//(是大寫字母就 check1 加一)
        }
        else if((code[i]>=48)&&(code[i]<=57))//number(數字)
        {
            check2++;//(是數字就 check2 加一)
        }
        else if(code[i]!=0)//neither capital letter nor small letter(既不是大寫字母也不是數字)
        {
            check3++;//(兩者都不是 check3 就加一)
        }
    }
    if(strlen(code)>10)//the amount of the string is larger than 10(字串超過10)
    {
        printf("Too long.");//太長了
    }
    else if(((check1== 0)&&(check2 != 0))||((check1 !=0)&&(check2 == 0))||(check3 != 0))//1.all are capital letter or number 2.one of the string is neither capital letter nor small letter
    {
        printf("Unrecognizable.");//(無法辨識)
    }
    else//(符合條件就執行)
    {
        for(j=0;j<strlen(code);j++)//(字串有多少就有多少)
        {
            if((code[j]<65)&&(code[j-1]>=65))//the last character is letter ,and the current one is number(第j-1字元是字母，而第j字元是數字)
            {
                for(k;k<j;k++)//(k初始值為0)//進行迴圈，到轉換字母到第j-1個字元就停下來，
                {
                    code[k]=code[k]+(code[j]-48);//字母加上數字
                    if(code[k]>90)//超過Z就跳回A繼續重新來
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
