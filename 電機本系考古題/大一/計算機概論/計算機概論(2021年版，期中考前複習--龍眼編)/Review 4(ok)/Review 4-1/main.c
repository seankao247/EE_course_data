#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    char color,my_color;
    char number,my_number;
    int num;
    srand(time(NULL));
    FILE*input;
    input = fopen("card.txt","w");
    num = rand()%52;
    switch(num/13)
    {
    case 0:
        fprintf(input,"C");
        break;
    case 1:
        fprintf(input,"D");
        break;
    case 2:
        fprintf(input,"H");
        break;
    case 3:
        fprintf(input,"S");
        break;
    }
    switch(num%13)
    {
    case 0:
        fprintf(input,"A");
        break;
    case 9:
        fprintf(input,"T");
        break;
    case 10:
        fprintf(input,"J");
        break;
    case 11:
        fprintf(input,"Q");
        break;
    case 12:
        fprintf(input,"K");
    default:
        fprintf(input,"%d",num%13+1);
    }

    printf("The enemy chose the card .\n");
    fclose(input);
    system("pause");

    input = fopen("card.txt","r");
    fscanf(input,"%c%c",&color,&number);

    printf("Please input your card :");
    scanf("%c%c",&my_color,&my_number);
    printf("The card of enemy is :%c%c\n",color,number);

    if((my_number == number)&&(my_color == color))
    {
        printf("BINGO");
    }
    else if (my_number != number)
    {
        if(my_number == 'A')
        {
            printf("SMALL");
        }
        else if(my_number == 'T')
        {
            if((number == 'J')||(number == 'Q')||(number == 'K'))
            {
                printf("SMALL");
            }
            else
            {
                printf("BIG");
            }
        }
        else if(my_number == 'J')
        {
            if((number == 'Q')||(number == 'K'))
            {
                printf("SMALL");
            }
            else
            {
                printf("BIG");
            }
        }
        else if(my_number == 'Q')
        {
            if(number == 'K')
            {
                printf("SMALL");
            }
            else
            {
                printf("BIG");
            }
        }
        else
        {
            if(my_number > number)
            {
                printf("BIG");
            }
            else
            {
                printf("SMALL");
            }
        }

    }
    else
    {
        if(my_color > color)
        {
            printf("BIG");
        }
        else
        {
            printf("SMALL");
        }
    }
    fclose(input);
    system("pause");
    return 0;
}
