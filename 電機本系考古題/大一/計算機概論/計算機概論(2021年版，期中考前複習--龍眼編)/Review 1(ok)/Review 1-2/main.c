#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n[10];
    double kg,m,cm,bmi;

    printf("你的名字 : ");
    scanf("%s",n);
    printf("身高 : ");
    scanf("%lf",&cm);
    printf("體重 : ");
    scanf("%lf",&kg);

    m = cm/100;
    bmi = kg/(m*m);

    printf("%s的BMI : %lf",n,bmi);

    return 0;
}
