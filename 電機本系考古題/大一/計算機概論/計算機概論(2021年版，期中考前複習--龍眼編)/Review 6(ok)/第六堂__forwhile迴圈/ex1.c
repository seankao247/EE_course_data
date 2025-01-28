/*Find prime number*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number[10]={0}; //prime
    int status; //status of the data
    int i,j,total=0,max=0,min=32767; //variable
    FILE *inp;
    /*read file*/
    inp = fopen("random.txt","r");

    printf("prime number : ");
    for(i = 0 ; i < 10 ; i++)
    {
        fscanf(inp,"%d",&number[i]);
        /*Printf the file information*/
        for(j = 2 ; j <= (number[i]-1) ; j++)
        {
            if(number[i] % j == 0)
            break;
        }
        if(j==number[i])
        {
            printf("%d ",number[i]);
            /*Calculate the number of primes*/
            total++;
            /*Find the maximum and minimum number of primes*/
            if(number[i] > max)
            {
                max = number[i];
            }
            if(number[i] < min)
            {
                min = number[i];
            }
        }
    }
    printf("\nmax prime number : %d",max);
    printf("\nmin prime number : %d",min);
    printf("\ntotal prime number : %d\n",total);
    fclose(inp);
    system("pause");
    return 0;
}
