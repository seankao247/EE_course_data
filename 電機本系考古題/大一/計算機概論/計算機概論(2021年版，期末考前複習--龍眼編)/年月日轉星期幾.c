#include <stdio.h>
#include <stdlib.h>
/*�p����:����Q�n�����(�~���)���b��Ƨ���date.txt�A����*/
/*reminder:please input the "year","month","day" in the file called "date.txt" in this folder.*/
/*�{���]���A���G�|��ܦbday.txt��*/
/*Waiting for the program finished , the result will be displayed in the file called "day.txt" in this folder.*/
int main()
{
    int y,m,d,yy;
    int count = 0,x;
    FILE*input;
    FILE*output;
    input = fopen("date.txt","r");
    output = fopen("day.txt","w");
    fscanf(input,"%d %d %d",&y,&m,&d);//Ū���~���
    yy = y;
    for(y=y-1;y>=1900;y--)//����~
    {
        if(((y%4==0)&&(y%100==0)&&(y%400==0))||((y%4==0)&&(y%100!=0)))//�|�~
        {
            count = count + 366;
        }
        else//���~
        {
            count = count + 365;
        }
    }
    y = yy;
    for(m;m>=1;m--)//�A���
    {
        if((m==2)||(m==4)||(m==6)||(m==8)||(m==9)||(m==11))//1�B3�B5�B7�B8�B10���`�@��31��
        {
            count = count + 31 ;
        }
        else if((m==5)||(m==7)||(m==10)||(m==12))//4�B6�B9�B11���`�@��30��
        {
            count = count + 30;
        }
        else if(m==3)//2��n�P�_�O�_���|�~
        {
            if(((y%4==0)&&(y%100==0)&&(y%400==0))||((y%4==0)&&(y%100!=0)))//�|�~�[29��
            {
                count = count + 29;
            }
            else//���~�[28��
            {
                count = count + 28;
            }
        }
    }
    count = count + d;
    printf("The Answer is in the file called day.txt");
    x = count%7;
    switch(x)
    {
        case 0:
            fprintf(output,"Today is Sunday.");
            break;
        case 1:
            fprintf(output,"Today is Monday.");
            break;
        case 2:
            fprintf(output,"Today is Tuesday.");
            break;
        case 3:
            fprintf(output,"Today is Wednesday.");
            break;
        case 4:
            fprintf(output,"Today is Thursday.");
            break;
        case 5:
            fprintf(output,"Today is Friday.");
            break;
        case 6:
            fprintf(output,"Today is Saturday.");
            break;
    }
    return 0;
}
