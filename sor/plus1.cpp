#include "../include/cpp_moduleBridge.h"
#include "../include/c_module.h"
using namespace std;
//加密
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
    cout<<endl;
    for(int i = 0; i < goal_len; i++) {
        free(matrix_t[i]);
    }
    free(matrix_t);//释放内存

}
//解密
extern "C" void de_function(const char* h,int goal_len,int key)
{
    srand(key);
    string s;
    string ini;
    s=h;
    //每个字符循环-3
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]=(s[i]-'A'-3+26)%26+'A';
        }
        if(s[i]>='a'&&s[i]<='z')
        {
            s[i]=(s[i]-'a'-3+26)%26+'a';
        }
        if(s[i]>='0'&&s[i]<='9')
        {
            s[i]=(s[i]-'0'-3+10)%10+'0';
        }
    }
    //转换成逆矩阵
    size_t cols = s.size() / goal_len;
    std::vector<std::string> a(goal_len, std::string(cols, '\0'));
    for(int row=0;row<goal_len;row++)
    {
        for(size_t col=0;col<cols;col++)
        {
            a[row][col]=s[col + row * cols];
        }
    }
    //把逆矩阵再转换为一行
    for(int i=0;i<(int)s.size()/goal_len;i++)
    {
        for(int j=0;j<goal_len;j++)
        {
            ini+=a[j][i];
        }
    }
    //根据随机数种子生成加密时可能生成的最大长度的随机数列
    string rand_alpha;
    char add;
    int rand_alpha_sum=0;
    for(int i=0;i<goal_len-1;)
    {
        add=rand()%123;
        if((add>=48&&add<=57)||(add>=65&&add<=90)||(add>=97&&add<=122))
        {
            rand_alpha+=(char)add;
            rand_alpha_sum++;
            i++;
        }
    }
    //遍历，从逆矩阵最后一列的第二个字符开始寻找，找能与rand_alpha完全重合的
    for(int i=(((int)ini.size()-goal_len)<0?0:(ini.size()-goal_len));i<(int)ini.size();i++)
    {
        if(ini[i]==rand_alpha[0])
        {
            for(int j=i;j<(int)ini.size();j++)
            {
                if(ini[j]!=rand_alpha[j-i])
                {
                    goto l;
                }
            }
            //抹去添加的随机字符串列
            ini.erase(i);
        }
        l:
        continue;
    }
    //输出
    cout<<ini;
}