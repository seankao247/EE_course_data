
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    char A[10];
    int s;
    printf("\t\tWelcome to CCU Bank(�w��Ө줤���j�ǻȦ�)\n");
    printf("We will provide you with English and Chinese Subtitles.(�ڭ̴��Ѥ��^�r��)\n");
    printf("Do you use the device for the first time?(�аݧA�Ĥ@���ϥζ�?)\n");
    printf("Please answer 'yes' or 'no'(�Ц^��'yes'�M'no')");
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
        printf("Wrong command.(���~���O)\nBYE!");
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
    printf("\n\nMr.Oscal Chen donated some money for you(���۱j���ͮ��اA�@�Ǹ��)\nNow your balance in the bank (�{�b�A�Ȧ�̦�): %d",money);
    fprintf(passbook,"%7s %18s %20d %20d","Others","Donated",money,money);
    fprintf(passbook,"\n");
    fclose(passbook);
    printf("\nDo you agree to continue the execution?(�A�P�N�˸m�~������?)\n");
    printf("Please answer 'yes' or 'no'(�Ц^��'yes'�M'no')");
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
        printf("Wrong command.(���~���O)\nBYE!");
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
    printf("Now your balance in the bank (�{�b�A�Ȧ�̦�): %d",balance);
    fprintf(passbook,"\n");
    fclose(passbook);
    printf("\nDo you agree to continue the execution?(�A�P�N�˸m�~������?)\n");
    printf("Please answer 'yes' or 'no'(�Ц^��'yes'�M'no')");
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
        printf("What function do you want to use?(�п�ܾާ@�覡)\n");
        printf("#1.Remaining(�O�d)\n#2.Withdraw(����)\n#3.Transfer(��b)\n#4.Deposit(�s��)\n");
        printf("Your choice : ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("\nOK!\n");
        }
        else if(choice == 2)
        {
            printf("\nPlease enter the money you want to withdraw(�п�J���ڪ��B) : ");
            scanf("%d",&money);
            printf("Please enter the usage of the money(�п�J�Ӫ������\��) : ");
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
            printf("\nNow the balance is %d dollars in your account.(�{�b�z�b��̪��l�B�ѤU%d��)\n",balance,balance);
            fclose(passbook);
        }
        else if(choice == 3)
        {
            printf("\nPlease enter the money you want to transfer(�п�J��b���B) : ");
            scanf("%d",&money);
            printf("Please enter the account in which the money are transfered (�п�J��J���b��) : ");
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
            printf("\nNow the balance is %d dollars in your account.(�{�b�z�b��̪��l�B�ѤU%d��)\n",balance,balance);
            fclose(passbook);
        }
        else if(choice == 4)
        {
            printf("\nPlease enter the money you want to deposit(�п�J�s�ڪ��B) : ");
            scanf("%d",&money);
            printf("Please enter the usage of the money(�п�J�Ӫ������γ~)");
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
            printf("\nNow the balance is %d dollars in your account.(�{�b�z���b��̪��l�B�ѤU%d��\n)",balance,balance);
            fclose(passbook);
        }
        else
        {
            printf("Wrong command(���~���O)\n");
        }
        printf("\nDo you want to continue to use  the device(�аݱz�n�~��ϥΦ��˸m��?)\n");
        printf("Please answer 'yes' or 'no'(�Ц^��'yes'�M'no')");
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
            printf("Wrong command.(���~���O)\nBYE!");
            break;
        }
    }
}
