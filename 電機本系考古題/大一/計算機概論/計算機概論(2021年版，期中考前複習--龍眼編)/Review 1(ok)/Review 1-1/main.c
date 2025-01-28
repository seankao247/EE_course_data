#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    int number,money;
    printf("鳳梨酥和鳳梨醋共買了幾個 ?\n");
    scanf("%d",&number);
    printf("總共花了多少錢 ?\n");
    scanf("%d",&money);
    /*列出算式*/
    b = (money - 400 * number)/100;
    a = number - b;
    c = money / 700;
    /*寫出結果*/
    printf("你買了%d個鳳梨酥和%d個鳳梨醋\n",a,b);
    printf("你可以換到%d個洗手瓶",c);
    return 0;
}
