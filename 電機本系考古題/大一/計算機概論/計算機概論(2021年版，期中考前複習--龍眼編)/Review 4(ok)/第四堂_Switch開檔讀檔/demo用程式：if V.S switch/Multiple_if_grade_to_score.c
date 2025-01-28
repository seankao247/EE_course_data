/*Multiple-Alternative Decisions using if
  Let the user enter a grade level, and then output a score range.
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char grade;               //the character the user enters

    printf("Please enter the grade: ");
    scanf("%c", &grade);      //the user enters a character

    /*There are 5 different score ranges.*/
    if(grade == 'A')
        printf("\nScore: 90＃\n\n");
    else if(grade == 'B')
        printf("\nScore: 80＃\n\n");
    else if(grade == 'C')
        printf("\nScore: 70＃\n\n");
    else if(grade == 'D')
        printf("\nScore: 60＃\n\n");
    else
        printf("\nYou failed!!!\n\n");

        return 0;
}
