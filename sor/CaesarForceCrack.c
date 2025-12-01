#include "../include/c_module.h"

void CaesarForceCrack(const char* text){
    size_t len=strlen(text);
    if (len>25)len=25; //限制最大长度，防止输出过长

    char result[MAX];
    for(int key=1;key<26;key++){
        printf("Trying key %d:\n",key);
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
        printf("%s\n",result);
    }
}