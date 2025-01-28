#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char n[10];
    double kg,m,cm,bmi;

    printf("length : ");
    scanf("%lf",&cm);
    printf("weight : ");
    scanf("%lf",&kg);

    m = cm/100;
    bmi = kg/(m*m);

    printf("BMI : %lf\n",bmi);

    if(bmi >= 27)
    {
        printf("fat");
    }
    else if((bmi >= 24)&&(bmi < 27))
    {
        printf("little fat");
    }
    else if ((bmi >= 18.5)&&(bmi < 24))
    {
        printf("normal");
    }
    else
    {
        printf("thin");
    }
    return 0;
}
