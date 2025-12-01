#ifndef CPP_BRIDGE_H
#define CPP_BRIDGE_H

#ifdef __cplusplus
#include<algorithm>
#include<iostream>
#include<vector>
#include<random>
#include<cmath>

extern "C" {
#else
#include<stdlib.h>
#include<stdio.h>
#endif

// 在这里声明C++函数
//void cpp_function_1(void);
//int cpp_calculate(int a, int b);
void function(const char* a,int b,int key);

#ifdef __cplusplus
}
#endif

#endif