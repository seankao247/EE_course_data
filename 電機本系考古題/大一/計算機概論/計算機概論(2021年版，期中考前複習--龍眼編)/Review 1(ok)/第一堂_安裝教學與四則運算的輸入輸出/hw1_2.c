#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    //BMI = �魫(����) / ����������(����)
    double x,y;
    char name[2];
    printf("�п�J�z���^��W:");
    scanf("%s",name);
    printf("�п�J�魫:");
    scanf("%lf",&x);
    printf("�п�J����:");
    scanf("%lf",&y);
   
    printf("%s�� BMI�� %lf\n",name,x/pow((y/100),2));

    system("pause");
    return 0;
}
