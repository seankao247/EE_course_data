#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double number;
    int a,b,c;
    printf("請輸入一個整數位為零的小數a:\n");
    while(scanf("%lf",&number)!=EOF){
       //0.124
        a=(int)(number/0.1);  //1
        b=(int)(number/0.01-10*a);   //2
        c=(int)(number/0.001-100*a-10*b); //4
        printf("總合為%d\n",a+b+c);
        if((a+b+c)%3==0)
        printf("為3的倍數\n");
        else
        printf("不是3的倍數\n\n");
    }
    system("pause");
    return 0;

}

