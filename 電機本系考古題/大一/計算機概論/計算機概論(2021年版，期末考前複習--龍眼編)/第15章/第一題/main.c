#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice,score;
    char name[100],answer[5];
    FILE*input;
    for(;;)
    {
        printf("Please choose the following functions(請選擇功能)\n");
        printf("#1.examine(檢視成績)\n#2.Remove(移除資料)\n#3.Exit(離開)\nYour choice(你的選擇):");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\nPlease enter the student's name(請輸入學生名字):");
            scanf("%s",name);
            strcat(name,".txt");
            input = fopen(name,"r");
            if(input==NULL)
            {
                printf("Do you want to create the file of this student?(你想要新增該學生的資料嗎？)\n");
                printf("Please enter 'yes' or 'no'(請輸入yes或no):");
                scanf("%s",answer);
                if(strcmp(answer,"yes")==0)
                {
                    input = fopen(name,"w");
                    printf("\nChinese(中文):");
                    scanf("%d",&score);
                    fprintf(input,"%d\t",score);
                    printf("\nEnglish(英文):");
                    scanf("%d",&score);
                    fprintf(input,"%d\t",score);
                    printf("\nMath(數學):");
                    scanf("%d",&score);
                    fprintf(input,"%d\t",score);
                    fclose(input);
                }
            }
            else
            {
                printf("\\Subject(科目)\\");
                printf("\nChinese(中文):");
                fscanf(input,"%d",&score);
                printf("%d",score);
                printf("\nEnglish(英文):");
                fscanf(input,"%d",&score);
                printf("%d",score);
                printf("\nMath(數學):");
                fscanf(input,"%d",&score);
                printf("%d",score);
            }
            fclose(input);
            system("pause");
            system("cls");
        }
        else if(choice==2)
        {
            printf("\nPlease enter the student's name(請輸入學生名字):");
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
