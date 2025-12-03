#include "../include/c_module.h"
#include "../include/cpp_moduleBridge.h"

int main(){
    char choose[3];
    char text[MAX];
    

    int column,key;
    column=sqrt(MAX);  //默认列数为sqrt(MAX)
    

    printf("Please choose the method you want to use(请选择你想使用的功能):\n\n");
    printf("1.Classic Caesar encode(1.经典凯撒加密)\n");
    printf("2.Classic Caesar decode(2.经典凯撒解密)\n\n");

    printf("Do you want to Crack the Caesar cipher by force?(你想通过暴力破解凯撒密码吗?)\n");
    printf("Please enter 3 or 4 to have a try(请尝试输入3或4):\n");
    printf("3.Crack Classic Caesar cipher by force--by trying all the possible keys(暴力破解--所有可能的密钥)\n");
    printf("4.Crack Classic Caesar cipher by force--statistic method(暴力破解--统计方法)\n\n");

    printf("May be after trying the cracking method,you will find that the Classic Caesar cipher is not very secure.\n");
    printf("(在尝试了暴力破解方法后,你会发现经典凯撒密码并不是很安全)\n");
    printf("So,we provide you with two secure method(因此我们提供两个比较安全的方法):\n");
    printf("5.My Optimized1 Caesar encode(我的优化方法1)\n");
    printf("6.My Optimized1 Caesar decode(我的优化方法1)\n");
    printf("7.My Optimized2 Caesar encode(我的优化方法2)\n");
    printf("8.My Optimized2 Caesar decode(我的优化方法2)\n");

    printf("Now the program is ready(现在程序准备就绪):\n");
    printf("Enter S to start and enter Anothers to quit(输入s开始选择,输入其余任意键退出):\n");

while(1)
{   
    if (getchar()!='s'&&getchar()!='S'){
        break;
    }
    getchar();
    printf("Please enter your choice(请输入你的选择):\n");
    fgets(choose,3,stdin);
    if (choose[0]< '1' || choose[0] > '8') {
        printf("Invalid choice. Exiting.\n");
        printf("无效的选择。程序退出。\n");
        return 1;
    }else if (choose[1] !='\n'){
        int clear_buffer;
        while ((clear_buffer=getchar())!='\n' && clear_buffer!=EOF); // 如果输入发生了截断,清空输入缓冲区，
    }
            
    switch (choose[0]){
        case '1':
            printf("You chose Classic Caesar encode,please input your text and key\n");
            printf("你选择了经典凯撒加密,请输入你的文本和密钥\n");
            get_input_text(text);
            get_input_keys(&key,&column,choose[0]);
            printf("Here is the encoding result:\n");
            printf("加密结果如下:\n");
            Caesar(text,key);
            break;
        case '2':
            printf("You chose Classic Caesar decode,please input your text and key\n");
            printf("你选择了经典凯撒解密,请输入你的文本和密钥\n");
            get_input_text(text);
            get_input_keys(&key,&column,choose[0]);

            printf("Here is the decoding result:\n");
            printf("解密结果如下:\n");
            key=-key;
            Caesar(text,key);
            break;
        case '3':
            printf("Please input the decoded text");
            printf("你选择了通过暴力破解经典凯撒密码\n");
            get_input_text(text);

            printf("Here is the cracking result:\n");
            printf("破解结果如下:\n");
            CaesarForceCrack(text);
            printf("\nAlso,you can enter 4 to have a easier method to decode it by force.\n");
            printf("另外,你也可以输入4来使用一种更简单的方法进行暴力破解。\n");
            break;
        case '4':
            printf("You chose the easier method to crack Classic Caesar cipher by force\n");
            printf("你选择了通过统计方法暴力破解经典凯撒密码\n");
            printf("Please input the decoded text\n");
            printf("请输入解密文本\n");
            get_input_text(text);

            //这里调用C++函数实现更智能的破解
            printf("Here is the cracking result:\n");
            printf("破解结果如下:\n");

            char_count(text);
            break;
        
        case '5':
            
            printf("a more secure method: My Optimized1 Caesar cipher.\n");
            printf("一种由凯撒密码引伸的更安全的方法: 我的优化方法1。\n");
            printf("You chose My Optimized1 Caesar encode\n");
            printf("你选择了我的优化方法1加密\n");
            get_input_text(text);
            get_input_keys(&key,&column,choose[0]);
            printf("Here is the encoding result:\n");
            printf("加密结果如下:\n");
            function(text,column,key);
            break;
        case '6':

            printf("This is the decoding of My Optimized1 Caesar cipher.\n");
            printf("你选择了我的优化方法1解密\n");
            get_input_text(text);
            get_input_keys(&key,&column,choose[0]);
            printf("Here is the decoding result:\n");
            printf("解密结果如下:\n");
            de_function(text,column,key);

            break;
        case '7':
            printf("Another more secure method: My Optimized2 Caesar cipher.\n");
            printf("另一种由凯撒密码引伸的更安全的方法: 我的优化方法2。\n");
            printf("You chose My Optimized2 Caesar encode\n");
            printf("你选择了我的优化方法2加密\n");
            get_input_text(text);
            get_input_keys(&key,&column,choose[0]);
            printf("Here is the encoding result:\n");
            printf("加密结果如下:\n");
            stream_encrypt(text,key);
            break;
        case '8':
            printf("This is the decoding of My Optimized2 Caesar cipher.\n");
            printf("你选择了我的优化方法2解密\n");
            get_input_text(text);
            get_input_keys(&key,&column,choose[0]); 
            printf("Here is the decoding result:\n");
            printf("解密结果如下:\n");
            stream_decrypt(text,key);
            break;

        
        default:
            printf("Invalid choice. Exiting.\n");
            printf("无效的选择。程序退出。\n");
            return 1;
    }
    printf("Enter S to continue and enter Anothers to quit(输入s继续,输入其余任意键退出):\n");
}
    system("pause");
    return 0;
}