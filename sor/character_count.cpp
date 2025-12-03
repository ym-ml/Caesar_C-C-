#include "../include/cpp_moduleBridge.h"
#include "../include/c_module.h"
using namespace std;
extern "C" struct char_number
{
    int sum=0;
    char c;
};
extern "C" void char_count(const char* ori_char)
{
    string ori_str,fin_str;
    ori_str=ori_char;
    int len=(int)ori_str.size();
    char_number char_num[26];
    //初始化
    for(int i=0;i<26;i++)
    {
        char_num[i].c=i+'a';
    }
    //统计每个字符的出现次数
    for(int i=0;i<len;i++)
    {
        if(ori_str[i]>='A'&&ori_str[i]<='Z')
        {
            char_num[ori_str[i]-'A'].sum++;
        }
        else if(ori_str[i]>='a'&&ori_str[i]<='z')
        {
            char_num[ori_str[i]-'a'].sum++;
        }
    }
    char_number mid;
    //冒泡排序，降序
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25-i;j++)
        {
            if(char_num[j].sum<char_num[j+1].sum)
            {
                mid=char_num[j];
                char_num[j]=char_num[j+1];
                char_num[j+1]=mid;
            }
        }
    }
    //计算偏移量
    int excursion=0;
    for(int i=0;i<6;i++)
    {
        if(char_num[i].sum<=0)
        {
            break;//提前退出，如果字符很少
        }
        excursion=(char_num[i].c-'e')*(-1);
        fin_str=ori_str;
        //每一个字符都加上偏移量
        for(int j=0;j<len;j++)
        {
            if(fin_str[j]>='a'&&fin_str[j]<='z')
            {
                fin_str[j]=(fin_str[j]-'a'+excursion+26)%26+'a';
            }
            else if(fin_str[j]>='A'&&fin_str[j]<='Z')
            {
                fin_str[j]=(fin_str[j]-'A'+excursion+26)%26+'A';
            }
            else if(fin_str[j]>='0'&&fin_str[j]<='9')
            {
                fin_str[j]=(fin_str[j]-'0'+excursion%10+10)%10+'0';
            }
            cout<<fin_str[j];//直接输出
        }
        cout<<endl<<endl;
    }
}