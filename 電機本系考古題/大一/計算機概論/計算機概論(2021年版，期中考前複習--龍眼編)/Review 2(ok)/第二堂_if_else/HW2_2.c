#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double number;
    int a,b,c;
    printf("�п�J�@�Ӿ�Ʀ쬰�s���p��a:\n");
    while(scanf("%lf",&number)!=EOF){
       //0.124
        a=(int)(number/0.1);  //1
        b=(int)(number/0.01-10*a);   //2
        c=(int)(number/0.001-100*a-10*b); //4
        printf("�`�X��%d\n",a+b+c);
        if((a+b+c)%3==0)
        printf("��3������\n");
        else
        printf("���O3������\n\n");
    }
    system("pause");
    return 0;

}

