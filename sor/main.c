<<<<<<< HEAD
#include "../include/cpp_moduleBridge.h"
=======
#include "../include/c_module.h"
#include "../include/cpp_moduleBridge.h"

>>>>>>> 1a94f52916f87a0d51e9a88f89e0c8c988c090f1
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