#include <stdio.h>
#include <stdlib.h>
int main()
{
    char* storage=0;
    int length=0;
    while(1)
    {
        char input;
        printf("�п�J�r��:");
        scanf("%s",&input);
        if(input=='0')break;//��J0(�s)�ɰh�X
        char* name= malloc(sizeof(char)*(length+1));
        for(int i=0;i<length;i++)*(name+i)=*(storage+i);
        free(storage);
        storage=name;
        name[length]=input;
        length++;
    }
    printf("\n���Ƥ��e���Ʀr:\n");
    for(int i=0;i<length;i++)
    {
        printf("%c",*(storage+i));
    }
    return 0;
}
