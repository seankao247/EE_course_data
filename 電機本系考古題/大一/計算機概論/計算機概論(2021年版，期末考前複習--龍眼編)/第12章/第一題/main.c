#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Register();
void Signin();
void check(char,char);
int same = 0,notsame = 0,n,N;
int main()//Main Function
{
    int choice,s;
    char account[30];
    char password[30];
    int same = 0,notsame = 0;
    FILE*storage;
    storage = fopen("storage.txt","a");
    for(;;)
    {
        printf("What function do you want to use ?\n");
        printf("#1.Register.(���U)\n");
        printf("#2.Sign in.(�n�J)\n");
        printf("#3.Give up(���)\n");
        printf("Your Choice : ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            storage = fopen("storage.txt","a");
            printf("\n\n");
            printf("Please input your new account (�п�J�A���s�b��):\n");
            scanf("%s",&account);
            printf("Please input your new password (�п�J�A���s�K�X):\n");
            scanf("%s",&password);
            printf("\n\n");
            fprintf(storage,"%s   %s\n",account,password);
            printf("\n\nRegistration completed successfully (���U����)\n \n");
            fclose(storage);
            system("pause");
            system("cls");
        }
        else if(choice == 2)
        {
            for(;;)
            {
               storage = fopen("storage.txt","r");
               printf("\n\n");
               printf("Please input your account and password(�п�J�A���b�K)\n");
               printf("Account(�b��) : ");
               scanf("%s",&account);
               printf("Password(�K�X) : ");
               scanf("%s",&password);
               printf("\n\n");
               char x[30],y[30];
               s = fscanf(storage,"%s   %s",&x,&y);
               while(s!=EOF)
               {
                   n = strcmp(x,account);
                   N = strcmp(y,password);
                   if((n == 0)&&(N == 0))
                {
                    printf("You have successfully logged in(�n�J����)\n");
                    break;
                }
                   s = fscanf(storage,"%s   %s",&x,&y);
               }
               if (s==EOF)
               {
                   printf("ERROR");
               }
               fclose(storage);
               system("pause");
               system("cls");
               break;
            }
        }
        else if(choice == 3)
        {
            printf("\nFINISH");
            break;
        }
        else
        {
            printf("\nFUCK");
            break;
        }
        }
    return 0;
}
