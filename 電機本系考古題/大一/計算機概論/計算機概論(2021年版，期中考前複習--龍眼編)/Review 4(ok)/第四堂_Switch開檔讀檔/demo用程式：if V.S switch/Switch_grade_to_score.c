/*輸入等第換算成分數*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char grade;                      //使用者輸入的等第 (是字元)

    printf("Please enter the grade: ");
    scanf("%c", &grade);             //輸入等第

    switch(grade)                    //換算成分數
    {
    case 'A':                        //有五種分數範圍
        printf("\nScore: 90↑\n");
        break;
    case 'B':
        printf("\nScore: 80↑\n");
        break;
    case 'C':
        printf("\nScore: 70↑\n");
        break;
    case 'D':
        printf("\nScore: 60↑\n");
        break;
    default:
        printf("\nfailed\n");
    }

    return 0;
}
