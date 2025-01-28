#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    //BMI = 體重(公斤) / 身高的平方(公尺)
    double x,y;
    char name[2];
    printf("請輸入您的英文名:");
    scanf("%s",name);
    printf("請輸入體重:");
    scanf("%lf",&x);
    printf("請輸入身高:");
    scanf("%lf",&y);
   
    printf("%s的 BMI為 %lf\n",name,x/pow((y/100),2));

    system("pause");
    return 0;
}
