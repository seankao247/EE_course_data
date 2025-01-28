#include <stdio.h>
#include <stdlib.h>

int main()
{
	int j,i,k,a,b,m,n,h;


	while(1)
    {
        printf("輸入等腰梯形的上底長度 : ");
        scanf("%d",&m);
        printf("輸入等腰梯形的下底長度 : ");
        scanf("%d",&n);
        printf("\n\n\n");
        if (((m%2)!=(n%2))||m==n)                                //上下底長度需同時為奇數或偶數，並且上下底不相等
        {
            printf("無法構成等腰梯形,請重新輸入\n\n\n");
        }
        else if (m>n)                                           //上底較長的狀況
        {
            for(i=1;i<=(m-n)/2+1;i++)
            {
                for(j=1;j<=m-i+1;j++)
                {
                    if(j>=i)
                        printf("*");
                    else
                        printf(" ");
                }
                printf("\n");
            }
            break;
        }
        else                                                    //下底較長的狀況
        {
            for(i=1;i<=(n-m)/2+1;i++)
            {
                for(j=1;j<=(n-m)/2+m+i-1;j++)
                {
                    if(j>=(n-m)/2-i+2)
                        printf("*");
                    else
                        printf(" ");
                }
                printf("\n");
            }
            break;
        }
    }

	return 0;
}
