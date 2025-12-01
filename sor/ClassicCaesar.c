#include "../include/c_module.h"

void Caesar(const char* text, int key){
    int len=strlen(text);
    char result[MAX];
    for(int i=0;i<len;i++){
        char ch=text[i];
        if(ch>='A'&&ch<='Z'){
            result[i]=(ch-'A'+key+26)%26+'A';
        }
        else if(ch>='a'&&ch<='z'){
            result[i]=(ch-'a'+key+26)%26+'a';
        }
        else if(ch>='0'&&ch<='9'){
            result[i]=(ch-'0'+key+10)%10+'0';
        }
        else{
            result[i]=ch;
        }
    }
    result[len]='\0';
    printf("The result is:\n%s\n",result);
}