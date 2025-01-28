#include <stdio.h>
#include <stdlib.h>

int main()
{
    //假設鳳梨醋a瓶與鳳梨酥b盒總數量為x，兩種動物的總金額為y
    int x,y,a,b;
    printf("請輸入鳳梨醋與鳳梨酥總數量:");
    scanf("%d",&x);
    printf("請輸入兩種動物的總金額:");
    scanf("%d",&y);

    //滿700送洗手液一瓶。鳳梨酥一盒480元、鳳梨醋一瓶380
    b=(480*x-y)/100;
    a=x-b;
    printf("買了鳳梨醋%d瓶.鳳梨酥%d盒\n",a,b);
    printf("可換%d瓶洗手液\n",(y/700));
    system("pause");
    return 0;
}
