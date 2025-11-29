#include "../include/c_module.h"

void get_input(char *text, int *key, int *column){
    char input_keys[3];
    printf("Please enter the key.\nYou can use one number or two numbers as your key:\n");
    //scanf("%d",key); //key已经是指针类型
    fgets(input_keys,3,stdin);
    if(strlen(input_keys)==2){
        *key=input_keys[0]-'0';
        *column=input_keys[1]-'0';
    }
    else{
        *key=input_keys[0]-'0';
    }

    int clear_buffer;
    while ((clear_buffer=getchar())!='\n'&&clear_buffer!=EOF); //清空输入缓冲区
    
    printf("Please enter the text to be encoded\n");
    fgets(text,MAX,stdin);
    char *find;
    find=strrchr(text,'\n');
    if(find!=NULL){
        *find='\0';
    }//去掉换行符
}   