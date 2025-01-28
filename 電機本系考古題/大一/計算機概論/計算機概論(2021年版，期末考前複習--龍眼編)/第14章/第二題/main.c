#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x);
void main()
{
    double num,a,b,c,t,tem;
    int count=0;
    printf("Please input the upper bound,lower bound and tolerance.(請輸入上限、下限以及可容忍誤差 )\n");
    printf("Upper bound(上限)：");
    scanf("%lf",&a);
    printf("Lower bound(下限)：");
    scanf("%lf",&b);
    printf("Tolerance(誤差)：");
    scanf("%lf",&t);
    if((f(a)*f(b))>0.0)//沒有根
    {
        printf("\nThere isn't any root on this closed intervel.(這封閉區間裡沒有任何的根)\n");
    }
    else//有根
    {
        do
        {
            c = (a + b)/2.0;
            if(f(c)*f(a)<0.0)//a和c不同邊-->c直接取代b變成下一個b
            {
                b = c;
            }
            else if(f(c)*f(b)<0.0)//b和c不同邊-->c直接取代a變成下一個a
            {
                a = c;
            }
            count++;
        }while(fabs(f(c))>t);
        printf("\n\nExecute the Bisection method for %d times totally(.總共執行了%d次二分法)\n",count,count);
        printf("Answer(答案) : f(%.16f) = %.16f\n\n",c,f(c));
    }
}
double f(double x)
{
   double num;
   num = (pow(x,3)) + (pow(x,2)) - (2*x) -1;
   return num;
}
