#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double number;
    int a,b,c;
    printf("叫块俱计箂计a:\n");
    while(scanf("%lf",&number)!=EOF){
       //0.124
        a=(int)(number/0.1);  //1
        b=(int)(number/0.01-10*a);   //2
        c=(int)(number/0.001-100*a-10*b); //4
        printf("羆%d\n",a+b+c);
        if((a+b+c)%3==0)
        printf("3计\n");
        else
        printf("ぃ琌3计\n\n");
    }
    system("pause");
    return 0;

}

