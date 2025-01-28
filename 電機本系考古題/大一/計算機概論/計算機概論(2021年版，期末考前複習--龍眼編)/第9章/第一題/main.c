#include <stdio.h>
#include <stdlib.h>
void factorize(int);
int in(int,int);
int ba(int,int);

int main()
{
    int s;
    int x,y;
    FILE*input;
    input=fopen("data.txt","r");
    s=fscanf(input,"%d %d",&x,&y);
    while(s!=EOF)
    {
        factorize(x);
        factorize(y);
        printf("程そ计:%d\n",in(x,y));
        printf("程そ计:%d\n",ba(x,y));
        printf("\n");
        s=fscanf(input,"%d %d",&x,&y);
    }
}

void factorize(int number)
{
    int i,I;
    printf("%d借计だ秆:",number);
    for(i=2;i<=number;i++)
    {
        int count=0;
        while(number%i==0)
        {
            number = number/i;
            count++;
        }
        if(count>0)
        {
            if (i!=2)
            {
                printf("x ");
            }
            for(count;count>0;count--)
            {
                  if(count==1)
                  {
                      printf("%d ",i);
                  }
                  else
                  {
                      printf("%d x ",i);
                  }
            }
        }
    }
    printf("\n");
}

int in(int x,int y)
{
    while(x%y!=0)
    {
        int a=x%y;
        x=y;
        y=a;
    }
    return y;
}

int ba(int x,int y)
{
    int number=(x*y)/in(x,y);
    return number;
}
