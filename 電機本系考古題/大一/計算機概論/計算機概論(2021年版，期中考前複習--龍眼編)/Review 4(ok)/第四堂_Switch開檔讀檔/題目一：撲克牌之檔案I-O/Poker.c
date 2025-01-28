/*Generate a card and write the card into card.txt.
  And then use the card to play cards comparison.
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    FILE * input, * output;            //pointer to the input file, output file
    char color, color_user;            //suit of computer's card, suit of user's card
    char number, number_user;          //point on computer's card, point on user's card
    int random_num;                    //a random number used to generate the computer's card

    output = fopen("card.txt","w");

    /*Randomly generate a number.*/
    srand(time(NULL));
    random_num = rand() % 52;

    /*Get the suit of the card.*/
    switch(random_num / 13)
    {
    case 0:
        fprintf(output,"C");           //Club
        break;
    case 1:
        fprintf(output,"D");           //Diamond
        break;
    case 2:
        fprintf(output,"H");           //Heart
        break;
    default:
        fprintf(output,"S");           //Spade
    }

    /*Get the number of the card.*/
    switch(random_num % 13)
    {
    case 0:
        fprintf(output,"A");         //1
        break;
    case 9:
        fprintf(output,"T");         //10
        break;
    case 10:
        fprintf(output,"J");         //11
        break;
    case 11:
        fprintf(output,"Q");         //12
        break;
    case 12:
        fprintf(output,"K");         //13
        break;
    default:
        fprintf(output,"%d", random_num % 13 + 1);   //number 2~9
    }

    fclose(output);

    printf("The card has already been generated!!\n\n");
    system("pause");

    /*Read data from the file. Save the value of the computer's card.*/
    input = fopen("card.txt","r");
    fscanf(input,"%c%c",&color, &number);

    /*color = 'D';
    number = '2';*/

    printf("\nPlease enter the card: ");
    scanf("%c%c",&color_user, &number_user);
    printf("The reference card is: %c%c\n",color, number);

    /*Compare the colors and numbers.*/
    if(number_user == number && color_user == color)   //The colors and numbers are both the same.
        printf("Bingo!!\n\n");
    else if(number_user != number)  //The numbers aren't the same.
    {
        if(number_user == 'A')      //User enter number A. In ASC2:A==65, 2==50, 3==51......,T==84, J==74, Q==81  , K==75
        {
            printf("Too small!\n\n");
        }
        else if(number_user == 'T')  //User enter number T.
        {
            if(number == 'J' || number == 'Q' || number =='K')
                printf("Too small!\n\n");
            else
                printf("Too big!\n\n");
        }
         else if(number_user == 'J')   //User enter number J.
        {
            if(number == 'Q' || number =='K')
                printf("Too small!\n\n");
            else
                printf("Too big!\n\n");
        }
        else if(number_user == 'Q')  //User enter number Q.
        {
            if(number =='K')
                printf("Too small!\n\n");
            else
                printf("Too big!\n\n");
        }
        else if(number_user == 'K')  //User enter number K.
        {
                printf("Too big!\n\n");
        }
        else                        //User doesn't enter a number from the aboves.
        {
            if(number == 'A')
                printf("Too big!\n\n");
            else
            {
                if(number_user < number)
                printf("Too small!\n\n");
                else
                printf("Too big!\n\n");
            }
        }
    }
    else //if(number_user == number && color_user != color)  //The numbers are the same but colors aren't the same.
    {
        if(color_user < color)
            printf("Too small!\n\n");
        else
            printf("Too big!\n\n");
    }

    fclose(input);
    return 0;
}

