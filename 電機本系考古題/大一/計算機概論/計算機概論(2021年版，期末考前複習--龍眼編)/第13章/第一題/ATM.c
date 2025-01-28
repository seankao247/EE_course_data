
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    char A[10];
    int s;
    printf("\t\tWelcome to CCU Bank(歡迎來到中正大學銀行)\n");
    printf("We will provide you with English and Chinese Subtitles.(我們提供中英字幕)\n");
    printf("Do you use the device for the first time?(請問你第一次使用嗎?)\n");
    printf("Please answer 'yes' or 'no'(請回答'yes'和'no')");
    scanf("%s",&A);
    if(strcmp(A,"yes")==0)
    {
        first();
    }
    else if(strcmp(A,"no")==0)
    {
        second();
    }
    else
    {
        printf("Wrong command.(錯誤指令)\nBYE!");
    }
}
void first()
{
    int money;
    char A[10];
    FILE*passbook;
    passbook = fopen("passbook.txt","a+");
    fprintf(passbook,"%7s %15s %21s %22s\n","Function","Usage","Money","Balance");
    fprintf(passbook,"\n");
    srand(time(0));
    money = rand()%40001+10000;
    printf("\n\nMr.Oscal Chen donated some money for you(陳自強先生捐贈你一些資金)\nNow your balance in the bank (現在你銀行裡有): %d",money);
    fprintf(passbook,"%7s %18s %20d %20d","Others","Donated",money,money);
    fprintf(passbook,"\n");
    fclose(passbook);
    printf("\nDo you agree to continue the execution?(你同意裝置繼續執行嗎?)\n");
    printf("Please answer 'yes' or 'no'(請回答'yes'和'no')");
    scanf("%s",&A);
    if(strcmp(A,"yes")==0)
    {
        function();
    }
    else if(strcmp(A,"no")==0)
    {
        printf("\nBYE!");
    }
    else
    {
        printf("Wrong command.(錯誤指令)\nBYE!");
    }
}
void second()
{
    char F[30],U[30],A[10];
    int s,cost,balance;
    FILE*passbook;
    passbook = fopen("passbook.txt","a+");
    s = fscanf(passbook,"%s %s %d %d",F,U,&cost,&balance);
    do
    {
        s = fscanf(passbook,"%s %s %d %d",F,U,&cost,&balance);
    }while(s!=EOF);
    printf("Now your balance in the bank (現在你銀行裡有): %d",balance);
    fprintf(passbook,"\n");
    fclose(passbook);
    printf("\nDo you agree to continue the execution?(你同意裝置繼續執行嗎?)\n");
    printf("Please answer 'yes' or 'no'(請回答'yes'和'no')");
    scanf("%s",&A);
    if(strcmp(A,"yes")==0)
    {
        function();
    }
    else if(strcmp(A,"no")==0)
    {
        printf("\nBYE!");
    }
}
void function()
{
    char F[30],U[30],NU[30],A[10];
    int s,choice;
    int money,cost,balance;
    for(;;)
    {
        FILE*passbook;
        passbook = fopen("passbook.txt","a+");
        printf("What function do you want to use?(請選擇操作方式)\n");
        printf("#1.Remaining(保留)\n#2.Withdraw(提款)\n#3.Transfer(轉帳)\n#4.Deposit(存款)\n");
        printf("Your choice : ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("\nOK!\n");
        }
        else if(choice == 2)
        {
            printf("\nPlease enter the money you want to withdraw(請輸入提款金額) : ");
            scanf("%d",&money);
            printf("Please enter the usage of the money(請輸入該金錢的功能) : ");
            scanf("%s",NU);
            s = fscanf(passbook,"%s %s %d %d",F,U,&cost,&balance);
            do
            {
                s = fscanf(passbook,"%s %s %d %d",F,U,&cost,&balance);
            }while(s!=EOF);
            s = 11;
            balance = balance - money;
            fprintf(passbook,"%s %20s %20d %20d","Withdraw",NU,money,balance);
            fprintf(passbook,"\n");
            printf("\nNow the balance is %d dollars in your account.(現在您帳戶裡的餘額剩下%d元)\n",balance,balance);
            fclose(passbook);
        }
        else if(choice == 3)
        {
            printf("\nPlease enter the money you want to transfer(請輸入轉帳金額) : ");
            scanf("%d",&money);
            printf("Please enter the account in which the money are transfered (請輸入轉入的帳戶) : ");
             scanf("%s",NU);
            s = fscanf(passbook,"%s %s %d %d",F,U,&cost,&balance);
            do
            {
                s = fscanf(passbook,"%s %s %d %d",F,U,&cost,&balance);
            }while(s!=EOF);
            s = 11;
            balance = balance - money;
            fprintf(passbook,"%s %20s %20d %20d","Withdraw",NU,money,balance);
            fprintf(passbook,"\n");
            printf("\nNow the balance is %d dollars in your account.(現在您帳戶裡的餘額剩下%d元)\n",balance,balance);
            fclose(passbook);
        }
        else if(choice == 4)
        {
            printf("\nPlease enter the money you want to deposit(請輸入存款金額) : ");
            scanf("%d",&money);
            printf("Please enter the usage of the money(請輸入該金錢的用途)");
            scanf("%s",NU);
            s = fscanf(passbook,"%s %s %d %d",F,U,&cost,&balance);
            do
            {
                s = fscanf(passbook,"%s %s %d %d",F,U,&cost,&balance);
            }while(s!=EOF);
            s = 11;
            balance = balance + money;
            fprintf(passbook,"%s %20s %20d %20d","Deposit",NU,money,balance);
            fprintf(passbook,"\n");
            printf("\nNow the balance is %d dollars in your account.(現在您的帳戶裡的餘額剩下%d元\n)",balance,balance);
            fclose(passbook);
        }
        else
        {
            printf("Wrong command(錯誤指令)\n");
        }
        printf("\nDo you want to continue to use  the device(請問您要繼續使用此裝置嗎?)\n");
        printf("Please answer 'yes' or 'no'(請回答'yes'和'no')");
        scanf("%s",&A);
        if(strcmp(A,"yes")==0)
        {
            printf("\n\n");
        }
        else if(strcmp(A,"no")==0)
        {
            break;
        }
        else
        {
            printf("Wrong command.(錯誤指令)\nBYE!");
            break;
        }
    }
}
