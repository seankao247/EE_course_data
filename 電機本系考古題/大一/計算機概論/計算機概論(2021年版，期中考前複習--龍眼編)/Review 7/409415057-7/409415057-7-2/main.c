#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int N[6];
    int check[39]={0};
    int i=0,I=0;
    char f[6],n[6];
    int  rn[6],rf[6];
    int p,c,a[6],b[6];
    while(i<6)
        {
        N[i]=rand()%39;
        if(check[N[i]]==0)
            {
             check[N[i]]=1;
             i++;
            }
        }
    for(I;I<6;I++)
        {
        a[I]=N[I]/13;
        b[I]=N[I]%13;
        switch(a[I])
        {
        case 0 : f[I]='D'; rf[I]=1; break;
        case 1 : f[I]='H'; rf[I]=2; break;
        case 2 : f[I]='S'; rf[I]=3; break;
        }
        switch(b[I])
        {
        case 0 : n[I]='A'; rn[I]=1; break;
        case 1 : n[I]='2'; rn[I]=2; break;
        case 2 : n[I]='3'; rn[I]=3; break;
        case 3 : n[I]='4'; rn[I]=4; break;
        case 4 : n[I]='5'; rn[I]=5; break;
        case 5 : n[I]='6'; rn[I]=6; break;
        case 6 : n[I]='7'; rn[I]=7; break;
        case 7 : n[I]='8'; rn[I]=8; break;
        case 8 : n[I]='9'; rn[I]=9; break;
        case 9 : n[I]='10';rn[I]=10;break;
        case 10: n[I]='J'; rn[I]=11;break;
        case 11: n[I]='Q'; rn[I]=12;break;
        case 12: n[I]='K'; rn[I]=13;break;
        }
        }
     p = (rn[0]*rf[0])+(rn[1]*rf[1])+(rn[2]*rf[2]);
     c = (rn[3]*rf[3])+(rn[4]*rf[4])+(rn[5]*rf[5]);
     printf("對手卡牌:\n%c%c\n%c%c\n%c%c\n",f[0],n[0],f[1],n[1],f[2],n[2]);
     printf("值:%d\n",p);
     printf("我的卡牌:\n%c%c\n%c%c\n%c%c\n",f[3],n[3],f[4],n[4],f[5],n[5]);
     printf("值:%d\n",c);
     if(p>c)
        {
        printf("你輸了\n");
        }
     else if(p<c)
        {
        printf("你贏了\n");
        }
     else
        {
        printf("平手\n");
        }
     system("pause");
     return 0;
}
