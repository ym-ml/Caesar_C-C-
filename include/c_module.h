#ifndef C_MODULE_H
#define C_MODULE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <errno.h>
#include <stdint.h> 

#define MAX 500

void get_input_text(char *text);
void get_input_keys(int *key, int *column,char choose);
void Caesar(const char* text, int key);
void CaesarForceCrack(const char* text);

// Stream cipher (基于可变凯撒位移的简单流密码)
// - stream_encrypt: 对输入文本逐字符应用不同的凯撒位移进行加密（仅对字母生效，保留大小写）
// - stream_decrypt: 使用相同种子和算法逆向位移以解密
void stream_encrypt(const char* input,  unsigned int seed);
void stream_decrypt(const char* input,  unsigned int seed);



#endif //C_MODULE_H