#include <stdio.h>
#include <stdlib.h>

int main()
{
    //���]����La�~�P����pb���`�ƶq��x�A��ذʪ����`���B��y
    int x,y,a,b;
    printf("�п�J����L�P����p�`�ƶq:");
    scanf("%d",&x);
    printf("�п�J��ذʪ����`���B:");
    scanf("%d",&y);

    //��700�e�~��G�@�~�C����p�@��480���B����L�@�~380
    b=(480*x-y)/100;
    a=x-b;
    printf("�R�F����L%d�~.����p%d��\n",a,b);
    printf("�i��%d�~�~��G\n",(y/700));
    system("pause");
    return 0;
}
