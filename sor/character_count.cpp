#include "../include/cpp_moduleBridge.h"
#include "../include/c_module.h"
using namespace std;
struct char_number
{
    int sum=0;
    char c;
};
void char_count(const char* ori_char)
{
    string ori_str,fin_str;
    ori_str=ori_char;
    int len=(int)ori_str.size();
    char_number char_num[26];
    for(int i=0;i<26;i++)
    {
        char_num[i].c=i+'a';
    }
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
    /*for(int i=0;i<26;i++)
    {
        cout<<char_num[i].c<<' '<<char_num[i].sum<<' '<<i<<endl;
    }*/
    int excursion=0;
    for(int i=0;i<26;i++)
    {
        if(char_num[i].sum<=0)
        {
            break;
        }
        excursion=char_num[i].c-'e';
        fin_str=ori_str;
        for(int i=0;i<len;i++)
        {
            if(fin_str[i]>='a'&&fin_str[i]<='z')
            {
                fin_str[i]=(fin_str[i]-'a'+excursion+26)%26+'a';
            }
            else if(fin_str[i]>='A'&&fin_str[i]<='Z')
            {
                fin_str[i]=(fin_str[i]-'A'+excursion+26)%26+'A';
            }
            else if(fin_str[i]>='0'&&fin_str[i]<='9')
            {
                fin_str[i]=(fin_str[i]-'0'+excursion%10+10)%10+'0';
            }
            cout<<fin_str[i];
        }
        cout<<' '<<i<<endl;
    }
}
