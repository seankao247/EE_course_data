#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice,score;
    char name[100],answer[5];
    FILE*input;
    for(;;)
    {
        printf("Please choose the following functions(�п�ܥ\��)\n");
        printf("#1.examine(�˵����Z)\n#2.Remove(�������)\n#3.Exit(���})\nYour choice(�A�����):");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\nPlease enter the student's name(�п�J�ǥͦW�r):");
            scanf("%s",name);
            strcat(name,".txt");
            input = fopen(name,"r");
            if(input==NULL)
            {
                printf("Do you want to create the file of this student?(�A�Q�n�s�W�Ӿǥͪ���ƶܡH)\n");
                printf("Please enter 'yes' or 'no'(�п�Jyes��no):");
                scanf("%s",answer);
                if(strcmp(answer,"yes")==0)
                {
                    input = fopen(name,"w");
                    printf("\nChinese(����):");
                    scanf("%d",&score);
                    fprintf(input,"%d\t",score);
                    printf("\nEnglish(�^��):");
                    scanf("%d",&score);
                    fprintf(input,"%d\t",score);
                    printf("\nMath(�ƾ�):");
                    scanf("%d",&score);
                    fprintf(input,"%d\t",score);
                    fclose(input);
                }
            }
            else
            {
                printf("\\Subject(���)\\");
                printf("\nChinese(����):");
                fscanf(input,"%d",&score);
                printf("%d",score);
                printf("\nEnglish(�^��):");
                fscanf(input,"%d",&score);
                printf("%d",score);
                printf("\nMath(�ƾ�):");
                fscanf(input,"%d",&score);
                printf("%d",score);
            }
            fclose(input);
            system("pause");
            system("cls");
        }
        else if(choice==2)
        {
            printf("\nPlease enter the student's name(�п�J�ǥͦW�r):");
            scanf("%s",name);
            strcat(name,".txt");
            remove(name);
            system("pause");
            system("cls");
        }
        else
        {
            break;
        }
    }
}
