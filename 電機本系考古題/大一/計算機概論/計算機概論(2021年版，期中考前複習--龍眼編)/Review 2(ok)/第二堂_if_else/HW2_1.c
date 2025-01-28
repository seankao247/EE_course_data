#include <stdio.h>

#include <math.h>
int main()
{
   int a,b,c,x1,x2,buf,D;
   /*利用公式解解題會比較快*/
    while (scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        D=pow(b,2)-4*a*c;
        if(D<0){
            printf("No real root\n");
        }
        else if(D==0){
            x1=(-b+pow(D,0.5))/(2*a);
            printf("Two same roots x=%d\n",x1);
        }
        else{
            x1=(-b+pow(D,0.5))/(2*a);
            x2=(-b-pow(D,0.5))/(2*a);
            if(x2>x1){
                buf=x1; //start change
                x1=x2;
                x2=buf;
            }
            printf("Two different roots x1=%d , x2=%d\n",x1,x2);
        }
    }
} 
