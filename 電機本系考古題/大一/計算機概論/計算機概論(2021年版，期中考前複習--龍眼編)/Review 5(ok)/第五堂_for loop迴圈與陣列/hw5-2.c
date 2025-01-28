#include <stdlib.h>
#include <stdio.h>
int main()
{
    FILE * input, * output;                        //pointer to input file, output file
    int year,month,day,i,sum;
    input = fopen("date4.txt", "r");
    output = fopen("result.txt", "w");

    fscanf(input,"%d %d %d",&year,&month,&day);
    //year=1998;
    //month=4;
    //day=1;
    sum=0;
    for(i=1900; i<year; i++)                  //Judge whether it is a leap year or not.
    {
        if((i%4==0&&i%100!=0)||(i%400==0))
        {
            sum=sum+366;
        }
        else
            sum=sum+365;;
    }
    for(i=1; i<month; i++)  //Compute the sum of days
    {
        switch(i)
        {
        case 1:
            sum=sum+31;
            break;
        case 2:
            sum=sum+28;
            break;
        case 3:
            sum=sum+31;
            break;
        case 4:
            sum=sum+30;
            break;
        case 5:
            sum=sum+31;
            break;
        case 6:
            sum=sum+30;
            break;
        case 7:
            sum=sum+31;
            break;
        case 8:
            sum=sum+31;
            break;
        case 9:
            sum=sum+30;
            break;
        case 10:
            sum=sum+31;
            break;
        case 11:
            sum=sum+30;
            break;
        case 12:
            sum=sum+31;
            break;
        default:
            printf("The month doesn't exist.\n");
        }
    }
    if((year%4==0 && year%100!=0) || year%400==0)//Judge whether it is a leap year or not.
    {
        if(month>2)
            sum=sum+1;
    }
    sum=sum+day;               //Judge the day of the week.
    i=sum%7;
    switch(i)
    {
        case 0:
        printf("Sunday");
        break;
        case 1:
        printf("Monday");
        break;
        case 2:
        printf("Tuesday");
        break;
        case 3:
        printf("Wednesday");
        break;
        case 4:
        printf("Thursday");
        break;
        case 5:
        printf("Friday");
        break;
        case 6:
        printf("Saturday");
        break;
    }

    fprintf(output,"今天是星期 %d",i);
    fclose(input);
    fclose(output);    //close file
    return 0;
}
