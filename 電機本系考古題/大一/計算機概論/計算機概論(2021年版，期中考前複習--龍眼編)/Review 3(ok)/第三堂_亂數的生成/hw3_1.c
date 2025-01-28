#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int first,answer,add=0;
    char input;
    srand(time(NULL));
    first=(rand()%13)+1;
    answer=(rand()%11)+1;


    printf("your first card is:");

   /*display*/
    if(1<first && first<11 )
        printf("%d",(int)first);
    else if(first==1)
        printf("A");
    else if(first==11){
        printf("J");
        first=10;
    }
    else if(first==12){
         printf("Q");
         first=10;
    }

    else{
        printf("K");
        first=10;
    }

    printf("\nif you want to add card?");
    scanf("%c",&input);
    if(input=='y'){

         printf("your add card is:");
        /*display*/
         add=(rand()%13)+1;

        if(1<add && add<11 )
            printf("%d\n",add);
        else if(add==1)
            printf("A\n");
        else if(add==11){
            printf("J\n");
            add=10;
        }

        else if(first==12){
             printf("Q\n");
             add=10;
        }

        else{
            printf("K\n");
            add=10;
        }

        //BOOM???

        if(add+first>10){
            printf("BOOM!!\n");
            printf("player2 win\n");
            system("pause");
            return 0;
        }

        else
        printf("\n");
    }
    else if(input=='n'){
            printf("\n");
    }
    else{printf("EOF!!\n");}

    //Who WIN
    if(add+first>answer){
    printf("player2 number is:%d\n",answer);
    printf("player1 win\n");
    }
    else{
    printf("player2 number is:%d\n",answer);
    printf("player1 lose\n");
    }
    system("pause");
    return 0;
}


