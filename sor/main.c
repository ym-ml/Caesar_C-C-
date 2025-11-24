#include "../include/cpp_moduleBridge.h"
int main(){
    char a[500];
    int b,key;
    scanf("%d%d",&b,&key);
    int clear_buffer;
    while ((clear_buffer=getchar())!='\n'&&clear_buffer!=EOF);
    fgets(a,500,stdin);
    for(int i=0;i<500;i++)
    {
        if(a[i]=='\n')
        {
            a[i]='\0';
        }
    }
    function(a,b,key);
    system("pause");
    return 0;
}