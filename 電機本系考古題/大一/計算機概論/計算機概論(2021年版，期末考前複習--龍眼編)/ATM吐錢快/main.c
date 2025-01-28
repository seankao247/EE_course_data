#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void EF();
void CF();
int main()
{
    int choice ;
    printf("||ATM||\n\nPlease choose the language\n1.English\n2.¤¤¤å\n3.None\n\nYour choice : ");
    scanf("%d",&choice);
    system("cls");
    if(choice == 1)
    {
        EF();
    }
    else if(choice == 2)
    {
        CF();
    }
    return 0;
}
void EF()
{
    char P[100];
    int s;
    FILE*book;
    printf("||ATM||\nYour password : ");
    scanf("%s",P);
    strcat(P,".txt");
    printf("%s",P);
    book=fopen(P,"r");
    if(book==NULL)
    {
        printf("The account doesn't exist . \nDo you want to create this new account ?")
    }
    fclose(P);
}
void CF()
{

}
