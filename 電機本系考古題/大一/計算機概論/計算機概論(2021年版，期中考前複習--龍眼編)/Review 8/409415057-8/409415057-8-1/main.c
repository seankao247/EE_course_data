#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5]={0,0,0,0,0};                   /*儲存數據的陣列*/
    int k,i,PASS,x,ii;
    int j = 0;                              /*i和ii都是迴圈*/
    int J = 1;                              /*PASS是篩選迴圈，一次迴圈表進行一次完整的bubble sort*/
                                            /*J是判斷係數，若該次篩選迴圈沒進行任何bubble sort，則J=1*/
    printf("請輸入五個數據 :\n");
    scanf("%4d %4d %4d %4d %4d",&a[0],&a[1],&a[2],&a[3],&a[4]);
    printf("原本數據的順序 :\n");
    for(k = 0;k < 5;k++)
    {
        printf("%4d",a[k]);
    }
    for(PASS =0;PASS < 5 ;PASS++)          /*篩選迴圈*/
    {
        for(i = 0;i < 4;i++)                /*篩選迴圈裡的bubble sort*/
        {
            if(a[i]>a[i + 1])
            {
                x = a[i];
                a[i] = a[i + 1];
                a[i + 1] = x;
                j = 1;
            }
        }
        if((j == 1)&&(PASS < 4))             /*如果有進行bubble sort(j=1)，則顯示經過篩選幾次*/
        {
            printf("\n經過第%d次篩選 :\n",J);  /*J當初設定為1*/
            for(ii = 0;ii < 5-PASS;ii++)
            {
                printf("%4d",a[ii]);
            }
            J++;                             /*有篩選才會把J加1*/
            j = 0 ;                          /*j歸零*/
        }
        else if(PASS == 4)                   /*如果是最後一次篩選，則不顯示經過篩選幾次*/
        {
            printf("\n篩完後的正確順序 :\n");
            for(ii = 0;ii < 5;ii++)
            {
                printf("%4d",a[ii]);
            }
            j = 0 ;
        }
        else                                /*如果沒有進行bubble sort，則直接進行下一輪的篩選迴圈*/
        {
            j = 0 ;

        }
    }
    return 0;
}
