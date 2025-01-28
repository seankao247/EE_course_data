#include <stdio.h>
#include <stdlib.h>
int main()
{
    char* storage=0;
    int length=0;
    while(1)
    {
        char input;
        printf("請輸入字元:");
        scanf("%s",&input);
        if(input=='0')break;//輸入0(零)時退出
        char* name= malloc(sizeof(char)*(length+1));
        for(int i=0;i<length;i++)*(name+i)=*(storage+i);
        free(storage);
        storage=name;
        name[length]=input;
        length++;
    }
    printf("\n重複之前的數字:\n");
    for(int i=0;i<length;i++)
    {
        printf("%c",*(storage+i));
    }
    return 0;
}
