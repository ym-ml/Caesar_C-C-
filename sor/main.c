#include "../include/c_module.h"
#include "../include/cpp_moduleBridge.h"

int main(){
    int choose;
    char text[MAX];

    int column,key;
    column=sqrt(MAX);  //默认列数为sqrt(MAX)
    

    printf("Please choose the method you want to use(请选择你想使用的功能):\n");
    printf("1.Classic Caesar encode(1.经典凯撒加密)\n");
    printf("2.Classic Caesar decode(2.经典凯撒解密)\n");

    printf("Do you want to Crack the Caesar cipher by force?(你想通过暴力破解凯撒密码吗?)n");
    printf("Please enter 3 or 4 to have a try(请尝试输入3或4):\n");
    printf("3.Crack Classic Caesar cipher by force--by trying all the possible keys(暴力破解--所有可能的密钥)\n");
    printf("4.Crack Classic Caesar cipher by force--statistic method(暴力破解--统计方法)\n");

    printf("May be after trying the cracking method,you will find that the Classic Caesar cipher is not very secure.\n");
    printf("So,we provide you with two secure method:\n");
    printf("5.My Optimized1 Caesar encode\n");
    printf("6.My Optimized1 Caesar decode\n");
    printf("7.My Optimized2 Caesar encode\n");
    printf("8.My Optimized2 Caesar decode\n");
    scanf("%d",&choose);
    switch (choose){
        case 1:
            printf("You chose Classic Caesar encode,please input your text and key\n");
            get_input_text(text);
            get_input_keys(&key,&column,choose);
            printf("Here is the encoding result:\n");
            Caesar(text,key);
            break;
        case 2:
            printf("You chose Classic Caesar decode,please input your text and key\n");
            get_input_text(text);
            get_input_keys(&key,&column,choose);

            printf("Here is the decoding result:\n");
            key=-key;
            Caesar(text,key);
            break;
        case 3:
            printf("Please input the decoded text");
            get_input_text(text);

            printf("Here is the cracking result:\n");
            CaesarForceCrack(text);
            printf("\nAlso,you can enter 4 to have a easier method to decode it by force.\n");
            break;
        case 4:
            printf("You chose the easier method to crack Classic Caesar cipher by force\n");
            printf("Please input the decoded text\n");
            get_input_text(text);

            //这里调用C++函数实现更智能的破解
            printf("Here is the cracking result:\n");

            break;
        
        case 5:
            
            printf("a more secure method: My Optimized1 Caesar cipher.\n");
            printf("You chose My Optimized1 Caesar encode\n");
            printf("Here is the encoding result:\n");
            get_input_text(text);
            get_input_keys(&key,&column,choose);
            function(text,column,key);
            break;
        case 6:
            break;

        
        default:
            printf("Invalid choice. Exiting.\n");
            return 1;
    }
    
    function(text,column,key);
    system("pause");
    return 0;
}