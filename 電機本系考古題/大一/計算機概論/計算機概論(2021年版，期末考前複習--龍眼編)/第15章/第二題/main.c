#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    int c1=0,c2=0,c3=0,i=0,j=0,k=0,s;
    char code[100];
    FILE*input;
    input = fopen("code.txt","r");
    s = fscanf(input,"%s",code);
    while(s!=EOF)
    {
        for(i;i<strlen(code);i++)
        {
            if((code[i]>=65)&&(code[i]<=90))//大寫字母
            {
                c1++;
            }
            else if((code[i]>=48)&&(code[i]<=57))//數字
            {
                c2++;
            }
            else//其他字元
            {
                c3++;
            }
        }
        i=0;
        if(strlen(code)>10)//長度超過10
        {
            printf("Too Long.\n");
            c1=0;
            c2=0;
            c3=0;
        }
        else if(((c1==0)&&(c2!=0))||((c1!=0)&&(c2==0))||(c3!=0))//字元條件不符合
        {
            printf("Unrecognizable\n");
            c1=0;
            c2=0;
            c3=0;
        }
        else
        {
            c1=0;
            c2=0;
            c3=0;
            for(j;j<strlen(code);j++)
            {
                if((code[j-1]>=65)&&(code[j]<65))
                {
                    for(k;k<j;k++)
                    {
                        code[k]=code[k]+(code[j]-48);
                        if(code[k]>90)
                        {
                            code[k]=code[k]-26;
                        }
                    }
                    k=j;
                }
            }
            k=0;
            j=0;
            for(i;i<strlen(code);i++)
            {
                if(code[i]>=65)
                {
                    printf("%c",code[i]);
                }
            }
            i=0;
        }
        printf("\n");
        s = fscanf(input,"%s",code);
    }
    fclose(input);
}
