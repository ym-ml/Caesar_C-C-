#include "../include/c_module.h"


// 简单 LCG(线性同余发生器) 用于生成伪随机位移序列
static uint32_t lcg_next(uint32_t *state){
    *state = (*state * 1103515245u + 12345u) & 0x7fffffffu;
    return *state;
}

// 对字母字符逐个应用可变凯撒位移进行加密（保留大小写），非字母保持不变
void stream_encrypt(const char* input, unsigned int seed){
    char output[MAX];

    uint32_t state = (uint32_t)seed;
    size_t i = 0;
    for(; input[i] != '\0'; ++i){
        unsigned char c = (unsigned char)input[i];
        if(isalpha(c)){
            uint32_t r = lcg_next(&state);
            int shift = (int)(r % 26u);
            if(isupper(c)){
                output[i] = (char)('A' + ( (c - 'A' + shift) % 26 ));
            }else{
                output[i] = (char)('a' + ( (c - 'a' + shift) % 26 ));
            }
        }else{
            output[i] = (char)c;
        }
    }
    output[i] = '\0';
    printf("The encoded result is:\n%s\n", output);
}

// 使用相同的种子和 LCG 序列按相反方向位移以解密
void stream_decrypt(const char* input, unsigned int seed){
    char output[MAX];
    
    uint32_t state = (uint32_t)seed;
    size_t i = 0;
    for(; input[i] != '\0'; ++i){
        unsigned char c = (unsigned char)input[i];
        if(isalpha(c)){
            uint32_t r = lcg_next(&state);
            int shift = (int)(r % 26u);
            if(isupper(c)){
                output[i] = (char)('A' + ( (c - 'A' - shift + 26) % 26 ));
            }else{
                output[i] = (char)('a' + ( (c - 'a' - shift + 26) % 26 ));
            }
        }else{
            output[i] = (char)c;
        }
    }
    output[i] = '\0';
    printf("The decoded result is:\n%s\n", output);
}

/*
    流密码实现说明：
    基于线性同余发生器（LCG）生成伪随机位移序列
    选择任意 32-bit 无符号整数作为种子即可；相同种子用于加解密。
    本实现仅为教学/演示目的，LCG 强度有限，不建议用于生产级安全场景。
*/



