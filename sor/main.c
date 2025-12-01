#include "../include/c_module.h"
#include "../include/cpp_moduleBridge.h"

int main(){
    char text[MAX];

    int column,key;
    column=sqrt(MAX);
    get_input(text,&key,&column);
    function(text,column,key);
    system("pause");
    return 0;
}