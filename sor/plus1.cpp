#include "../include/cpp_moduleBridge.h"
#include "../include/c_module.h"
using namespace std;
extern "C" void function(const char* h,int goal_len,int key)
{
    string a=h;
    int len=ceil((float)a.size()/(float)goal_len)*goal_len;
    srand(key);
    int sum=(int)a.size(),add;
    while(sum<len)
    {
        add=rand()%123;
        if((add>=48&&add<=57)||(add>=65&&add<=90)||(add>=97&&add<=122))
        {
            a+=(char)add;
            sum++;
        }
    }

    char** matrix_t = (char**)malloc(goal_len * sizeof(char*));
    for(int i = 0; i < goal_len; i++) {
        matrix_t[i] = (char*)malloc((len/goal_len) * sizeof(char));
    }//动态分配二维数组

    for(int i=0;i<(len/goal_len);i++)
    {
        for(int j=i*goal_len;j<(int)((i+1)*goal_len);j++)
        {
            matrix_t[j%goal_len][i]=a[j];
        }
    }
    for(int i=0;i<goal_len;i++)
    {
        for(int j=0;j<len/goal_len;j++)
        {
            if(matrix_t[i][j]>='0'&&matrix_t[i][j]<='9')
            {
                matrix_t[i][j]=(matrix_t[i][j]-'0'+3)%10+'0';
            }
            if(matrix_t[i][j]>='a'&&matrix_t[i][j]<='z')
            {
                matrix_t[i][j]=(matrix_t[i][j]-'a'+3)%26+'a';
            }
            if(matrix_t[i][j]>='A'&&matrix_t[i][j]<='Z')
            {
                matrix_t[i][j]=(matrix_t[i][j]-'A'+3)%26+'A';
            }
            cout<<matrix_t[i][j];
        }
    
    }

    for(int i = 0; i < goal_len; i++) {
        free(matrix_t[i]);
    }
    free(matrix_t);//释放内存

}
