/*��J���Ĵ��⦨����*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char grade;                      //�ϥΪ̿�J������ (�O�r��)

    printf("Please enter the grade: ");
    scanf("%c", &grade);             //��J����

    switch(grade)                    //���⦨����
    {
    case 'A':                        //�����ؤ��ƽd��
        printf("\nScore: 90��\n");
        break;
    case 'B':
        printf("\nScore: 80��\n");
        break;
    case 'C':
        printf("\nScore: 70��\n");
        break;
    case 'D':
        printf("\nScore: 60��\n");
        break;
    default:
        printf("\nfailed\n");
    }

    return 0;
}
