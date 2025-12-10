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
    int max_proportion=0;
    int is_less=0;
    initgraph(800,600);//初始化图形窗口
    string ori_str;
    string fin_str;
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
            break;
            //提前退出，如果字符很少
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
    setbkcolor(WHITE);
    cleardevice();
    int data[5];
    for(int i=0;i<5;i++)
    {
        data[i]=char_num[i].sum;
    }
    int left,bottom;
    left=100;bottom=500;
    int datac=5;
    int axsis_x=600,axsis_y=400;
    //绘制坐标轴
    int bar_width=50;
    int s=(axsis_x-datac*bar_width)/(datac+1);
    setlinecolor(BLACK);
    setlinestyle(PS_SOLID,2);
    settextcolor(BLACK);
    settextstyle(20,0,_T("Arial"));
    for(int j=0;j<datac;j++)
    {
        int bar_h=(int)(((float)data[j]/(float)len)*(float)axsis_y);
        max_proportion=max(max_proportion,bar_h);
    }
    settextstyle(24,0,_T("Arial"));
    if(max_proportion<200)
    {
        is_less=1;
    }
    else
    {
        is_less=0;
    }
    //判断占比是否大于一半
    for(int j=0;j<datac;j++)
    {
        int bar_x=left+s+j*(bar_width+s);
        int bar_h=(int)(((float)data[j]/(float)len)*(float)axsis_y)*(is_less+1);
        max_proportion=max(max_proportion,bar_h);
        int bar_y=bottom-bar_h;
        setfillcolor(RGB(100,149,237));
        fillrectangle(bar_x,bar_y,bar_x+bar_width,bottom);
        string num=to_string(data[j]);
        outtextxy(bar_x+bar_width/2-10,bar_y-25,(num.c_str()));
        outtextxy(bar_x+bar_width/2-15,bottom+10,char_num[j].c);
    }
    line(left,bottom,left+axsis_x,bottom);//x轴
    line(left,bottom,left,bottom-axsis_y);//y轴
    for(int i=0;i<6;i++)
    {
        int y=bottom-i*(axsis_y/5);
        line(left-5,y,left,y);//y轴刻度
        string v=to_string(i*(is_less==0?20:10));
        outtextxy(left-40,y-8,v.c_str());
    }
    outtextxy(left+bar_width/2-60,bottom+50,"Character Frequency Histogram");
    outtextxy(left-60,bottom-axsis_y/2,"Frequency");
    system("pause");
    //closegraph();
}