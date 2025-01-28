#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x);
void main()
{
    double num,a,b,c,t,tem;
    int count=0;
    printf("Please input the upper bound,lower bound and tolerance.(�п�J�W���B�U���H�Υi�e�Ի~�t )\n");
    printf("Upper bound(�W��)�G");
    scanf("%lf",&a);
    printf("Lower bound(�U��)�G");
    scanf("%lf",&b);
    printf("Tolerance(�~�t)�G");
    scanf("%lf",&t);
    if((f(a)*f(b))>0.0)//�S����
    {
        printf("\nThere isn't any root on this closed intervel.(�o�ʳ��϶��̨S�����󪺮�)\n");
    }
    else//����
    {
        do
        {
            c = (a + b)/2.0;
            if(f(c)*f(a)<0.0)//a�Mc���P��-->c�������Nb�ܦ��U�@��b
            {
                b = c;
            }
            else if(f(c)*f(b)<0.0)//b�Mc���P��-->c�������Na�ܦ��U�@��a
            {
                a = c;
            }
            count++;
        }while(fabs(f(c))>t);
        printf("\n\nExecute the Bisection method for %d times totally(.�`�@����F%d���G���k)\n",count,count);
        printf("Answer(����) : f(%.16f) = %.16f\n\n",c,f(c));
    }
}
double f(double x)
{
   double num;
   num = (pow(x,3)) + (pow(x,2)) - (2*x) -1;
   return num;
}
