#include "../include/c_module.h"
#include "../include/cpp_moduleBridge.h"

int main(){
    char text[MAX];

    int column,key;
    column=sqrt(MAX);
    printf("Please enter the key:\n");
    scanf("%d",&key);

    int clear_buffer;
    while ((clear_buffer=getchar())!='\n'&&clear_buffer!=EOF); //清空输入缓冲区
    
    printf("Please enter the text to be encoded\n");
    fgets(text,MAX,stdin);
    for(int i=0;i<MAX;i++)
    {
        if(text[i]=='\n')
        {
            text[i]='\0';
        }
    }
    
    
    function(text,column,key);
    system("pause");
    return 0;
}