#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    while(1)
    {
        int m,d,y;
        char M[20];
        printf("Please write the date,which is month-day-year.\n#Ex. Jen. 1 2020 or Jenuary 1 2020\n");
        printf("\nYour Date : ");
        scanf("%s %d %d",M,d,y);
        if((strcmp(M,"Jan.")==0)&&(strcmp(M,"January")==0))
        {
            m=1;
        }
        else if((strcmp(M,"Feb.")==0)&&(strcmp(M,"February")==0))
        {
            m=2;
        }
        else if((strcmp(M,"Mar.")==0)&&(strcmp(M,"March")==0))
        {
            m=3;
        }
        else if((strcmp(M,"Apr.")==0)&&(strcmp(M,"April")==0))
        {
            m=4;
        }
        else if(strcmp(M,"May")==0)
        {
            m=5;
        }
        else if((strcmp(M,"June")==0)&&(strcmp(M,"Jun.")==0))
        {
            m=6;
        }
        else if((strcmp(M,"July")==0)&&(strcmp(M,"Jul.")==0))
        {
            m=7;
        }
        else if((strcmp(M,"August")==0)&&(strcmp(M,"Aug.")==0))
        {
            m=8;
        }
        else if((strcmp(M,"Semtember")==0)&&(strcmp(M,"Sem.")==0))
        {
            m=9;
        }
        else if((strcmp(M,"October")==0)&&(strcmp(M,"Oct.")==0))
        {
            m=10;
        }
        else if((strcmp(M,"November")==0)&&(strcmp(M,"Nov.")==0))
        {
            m=11;
        }
        else if((strcmp(M,"December")==0)&&(strcmp(M,"Dec.")==0))
        {
            m=12;
        }
    }
    return 0;
}
