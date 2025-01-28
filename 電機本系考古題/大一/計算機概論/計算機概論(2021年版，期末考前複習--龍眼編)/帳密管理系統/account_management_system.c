#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()//Main Function(主程式)
{
    int choice;
    printf("Welcome to ABC Website.\nWhat function you want to choose?\n");
    printf("#1.Log in\n#2.Register\n#3.Exit\nYour Choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 : Login();
        break;
        case 2 : Register();
        break;
        default :
        break;
    }
    return 0;
}
void Login()//Sub-function for logging in(登入副函式)
{
    int s;
    int A,B,same=0,choice;
    char x[50],y[50],a[50],b[50];
    FILE*storage;
    storage = fopen("storage.txt","r");
    while(1)
    {
        printf("\nPlease enter your account and password .\n");
        printf("*Account : ");
        scanf("%s",&x);
        printf("*Password : ");
        scanf("%s",&y);
        s = fscanf(storage,"%s %s",&a,&b);
        while(s!=EOF)
        {
            A = strcmp(x,a);
            B = strcmp(y,b);
            if((A == 0)&&(B == 0))
            {
                same++;
            }
            s = fscanf(storage,"%s %s",&a,&b);
        }
        if(same == 1)
        {
            same = 0;
            printf("\nYou have logged in successfully.");
            break;
        }
        else
        {
            same = 0;
            printf("\nThe account does not exist.");
            printf("\nWhat do you want to do right now?\n");
            printf("#1.Log in again\n#2.Create a new account\n#3.Exit.\n");
            printf("Your Choice : ");
            scanf("%d",&choice);
            if(choice == 2)
            {
                Register();
                break;
            }
            else if(choice == 3)
            {
                break;
            }
        }

    }
}
void Register()//Sub-function for registering(註冊副函式)
{
    char x[50],y[50],a[50],b[50];
    int s,A,B,choice;
    FILE*input;
    FILE*output;
    input = fopen("storage.txt","r");
    output = fopen("storage.txt","a");
    for(;;)
    {
        printf("\nPlease create a new and independent account and password\n");
        printf("*New account : ");
        scanf("%s",&x);
        printf("*New password : ");
        scanf("%s",&y);
        s = fscanf(input,"%s %s",&a,&b);
        while(s!=EOF)
        {
            A = strcmp(x,a);
            B = strcmp(y,b);
            if((A == 0)&&(B == 0))
            {
                printf("SORRY!The account had been registered.\n");
                printf("\nWhat do you want to do right now?\n");
                printf("#1.Register again\n#2.Try to log in\n#3.Exit.\n");
                printf("Your Choice : ");
                break;
            }
            s = fscanf(input,"%s %s",&a,&b);
        }
        if(s==EOF)
        {
            printf("\nYour Registration completed successfully.\n");
            fprintf(output,"\n%s %s",x,y);
            break;
        }
        else
        {
            scanf("%d",&choice);
            if(choice == 2)
            {
                Login();
                break;
            }
            else if(choice ==3)
            {
                break;
            }
        }
    }
}
