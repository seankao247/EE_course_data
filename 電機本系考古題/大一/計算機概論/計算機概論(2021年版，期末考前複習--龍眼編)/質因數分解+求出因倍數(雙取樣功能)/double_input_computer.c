#include <stdio.h>
#include <stdlib.h>

void text();
void data();
void factorize();
void main()
{
    int choice;
    printf("Choose the way you input the data.\n");
    printf("#Option 1.Use the external text file 'data.txt'.#\n");
    printf("#Option 2.Input data with your keyboard.#\n");
    printf("#Option 3.Give up right now.\n\n#");
    printf("Your Choice (input 1 , 2 or 3):");
    scanf("%d",&choice);
    printf("\n\n");

    switch(choice)
    {
        case 1: text(); break;
        case 2: data(); break;
        case 3: printf("Eat Shit bro!"); system("pause");break;
    }
}
void text()
{
    int s;
    int a,b;
    FILE*input;
    printf("Get your data from the file.\n\n");
    input = fopen("data.txt","r");
    s = fscanf(input,"%d %d",&a,&b);
    while(s != EOF)
    {
        factorize(a);
        factorize(b);
        printf("The highest common factor of %d and %d is : %d",a,b,hcf(a,b));
        printf("\nThe Least common multiple of %d and %d is : %d",a,b,lcm(a,b));
        printf("\n\n");
        s = fscanf(input,"%d %d",&a,&b);
    }
}
void factorize(int x)//Sub-function for integer factorization
{
    int i,count = 0;
    printf("The integer factorization of %d : ",x);
    for(i = 2 ; i <= x ; i ++)//Divided by 2 initially
    {
        while(x%i == 0)
        {
            x = x/i;
            count ++;
        }
        if(count > 0)
        {
            for(count ; count >0 ; count --)
            {
                if((x == 1)&&(count ==1))
                {
                    printf("%d",i);
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
int hcf(int x,int y)
{
    int tem;
    if(x < y)
    {
        tem = y;
        y = x;
        x = tem;
    }
    while(x%y != 0)
    {
        tem = x%y;
        x = y;
        y = tem;
    }
    return y;
}
int lcm(int x,int y)
{
    int number = (x*y)/(hcf(x,y));
    return number;
}
void data()
{
    for(;;)
    {
    int a,b,c;
    printf("Now please input your two number : ");
    scanf("%d %d",&a,&b);
    factorize(a);
    factorize(b);
    printf("The highest common factor of %d and %d is : %d",a,b,hcf(a,b));
    printf("\nThe Least common multiple of %d and %d is : %d",a,b,lcm(a,b));
    printf("\n\nDo you want to continue to input the data ? (Input '0' for agree or '1' for opposition)\n");
    scanf("%d",&c);
    if(c == 1)
    {
        printf("FINSH");
        break;
    }
    }
}

