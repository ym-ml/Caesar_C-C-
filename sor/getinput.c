#include "../include/c_module.h"

void get_input_text(char *text){
     
    printf("Please enter the text:\n");
    printf("请输入文本:\n");
    fgets(text,MAX,stdin);
    if (text[strlen(text)-1]!='\n'){
        int clear_buffer;
        while ((clear_buffer=getchar())!='\n'&&clear_buffer!=EOF); 
    }//如果输出被截断,清空输入缓冲区

    char *find;
    find=strrchr(text,'\n');
    if(find!=NULL){
        *find='\0';
    }//去掉换行符
    printf("Got it!\n");
    printf("Your input text is:\n%s\n",text);
    
}


void get_input_keys(int *key, int *column,char choose){
    char input_keys[5];
    switch (choose)
    {
    case '1':
    case '7':
        printf("Please enter the key(number):\n");
        printf("请输入密钥(数字):\n");
        break;
    case '2':
    case '8':
        printf("Please enter the same key of the encode:\n");
        printf("请输入加密时使用的相同密钥:\n");
       
        break;
    case '5':
        printf("Please enter the key.\nYou can use one number or two numbers as your key:\n");
        printf("请输入密钥。你可以使用一个数字或两个数字作为你的密钥:\n");
        break;
    case '6':
        printf("Please enter the key used in encoding.\nYou must use the same key of the encode:\n");
        printf("请输入加密时使用的密钥。你必须使用相同的密钥:\n");
        break;
    
    default:
        break;
    }

    //scanf("%d",key); //key已经是指针类型
    fgets(input_keys,10,stdin);

    if (input_keys[strlen(input_keys)-1]!='\n'){
        int clear_buffer;
        while ((clear_buffer=getchar())!='\n'&&clear_buffer!=EOF); 
    }//如果输出被截断,清空输入缓冲区

    char *find;
    find=strchr(input_keys,' ');
    

    if(find!=NULL){
        sscanf(input_keys,"%d %d",key,column);

    }else{
       sscanf(input_keys,"%d",key);
    }//解析输入的密钥
    printf("Got it!\n");
}