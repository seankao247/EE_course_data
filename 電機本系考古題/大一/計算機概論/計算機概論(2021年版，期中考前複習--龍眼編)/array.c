#include<stdio.h>

int main(int argc, int* argv[])
{
    int num = 0, exit = 1, step = 0, max =0, level = 0;
    int i = 0, j = 0;

    printf("please enter a num\n");
    scanf("%d", &num);
    max = num*num;

    int array[num][num];

    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            array[i][j] = 0;
        }
    }

    while(exit <= max)
    {

        array[i][j] = exit;

        switch(step)
        {
            case 0:
                j++;
                exit ++;
                if(j == (num-level-1))
                {
                    step ++;
                }
                break;
            case 1:
                i++;
                exit ++;

                if(i == (num-level-1))
                {
                    step ++;
                }
                break;
            case 2:
                j--;
                exit ++;
                if(j == (level))
                {
                    step ++;
                }
                break;
            case 3:
                i--;
                exit ++;
                if(i == level+1)
                {
                    step ++;
                }
                break;
        }

        if(step == 4)
        {
            step = 0;
            level ++;
        }
    }

    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
