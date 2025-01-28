#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p,i,I,s;
    int array[7];
    FILE*input;
    input=fopen("password.txt","r");
    s=fscanf(input,"%d",&p);
    while(s!=EOF)
    {
         printf("original number:%d\n",p);
         for(i=0;i<7;i++)
         {
          array[i]=p%10;
          array[i]+=3;
          if(array[i]>9)
            {
            array[i]=array[i]-10;
            }
          p=p/10;
         }
         printf("changed number:");
         for(I=0;I<7;I++)
        {
          printf("%d",array[I]);
         }
        printf("\n\n");
        s=fscanf(input,"%d",&p);
    }
    return 0;
}
