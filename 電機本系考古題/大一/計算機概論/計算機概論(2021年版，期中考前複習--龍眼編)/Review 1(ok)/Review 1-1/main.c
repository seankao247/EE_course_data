#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    int number,money;
    printf("����p�M����L�@�R�F�X�� ?\n");
    scanf("%d",&number);
    printf("�`�@��F�h�ֿ� ?\n");
    scanf("%d",&money);
    /*�C�X�⦡*/
    b = (money - 400 * number)/100;
    a = number - b;
    c = money / 700;
    /*�g�X���G*/
    printf("�A�R�F%d�ӻ���p�M%d�ӻ���L\n",a,b);
    printf("�A�i�H����%d�Ӭ~��~",c);
    return 0;
}
