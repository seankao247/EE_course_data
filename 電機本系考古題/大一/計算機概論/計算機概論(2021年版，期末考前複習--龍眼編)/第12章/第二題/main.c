#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int a[3][3],e[9];
    char n[9];
    int number=0,i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            number++;
            a[i][j]=number;
            printf("%d  ",a[i][j]);//印出3x3的數字1到9
        }
        printf("\n");
    }
    for(i=0;i<3;i++)//數字1到9的位置全部歸零
    {
        for(j=0;j<3;j++)
        {
            a[i][j]=0;
        }
    }
    printf("Please create a password(請創造一個圖形密碼):");
    scanf("%s",&n);
    for(k=0;k<9;k++)
    {
        switch(n[k])//點到該數字位置就變1否則就不變
        {
            case '1':a[0][0]=1;break;
            case '2':a[0][1]=1;break;
            case '3':a[0][2]=1;break;
            case '4':a[1][0]=1;break;
            case '5':a[1][1]=1;break;
            case '6':a[1][2]=1;break;
            case '7':a[2][0]=1;break;
            case '8':a[2][1]=1;break;
            case '9':a[2][2]=1;break;
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
    for(;;)
    {
        printf("Please login the correct password.(請輸入正確密碼)");
        scanf("%s",e);
        if(strcmp(n,e)==0)
        {
            printf("Sign in successfully(登入成功)\n");
            break;
        }
        else
        {
            printf("Error(錯誤)\n");
            printf("Please resign in.(請重新登入)\n");
        }
    }
}
