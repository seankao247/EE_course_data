#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n[10];
    double kg,m,cm,bmi;

    printf("�A���W�r : ");
    scanf("%s",n);
    printf("���� : ");
    scanf("%lf",&cm);
    printf("�魫 : ");
    scanf("%lf",&kg);

    m = cm/100;
    bmi = kg/(m*m);

    printf("%s��BMI : %lf",n,bmi);

    return 0;
}
