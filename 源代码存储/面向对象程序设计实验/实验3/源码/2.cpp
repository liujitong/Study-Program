#include<iostream>
using namespace std;
//i.定义Time类和Date类；
class Time
{ 
protected:
    int hour;
    int minute;
    int second;
public:
    Time(int h,int m,int s)
    {
        hour=h;
        minute=m;
        second=s;
    }
    void print()
    {
        cout<<hour<<":"<<minute<<":"<<second<<endl;
    }
};
class Date
{
protected:
    int year;
    int month;
    int day;
public:
    Date(int y,int m,int d)
    {
        year=y;
        month=m;
        day=d;
    }
    void print()
    {
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }
};
//ii.设计Birthtime类，它继承了Time类和Date类，并且还有一项出生孩子的名字Childname；
class Birthtime:public Time,public Date
{
protected:
    string Childname;
public:
    Birthtime(int h,int m,int s,int y,int m1,int d,string name):Time(h,m,s),Date(y,m1,d)
    {
        Childname=name;
    }
    void print()
    {
        cout<<"出生时间：";
        Time::print();
        cout<<"出生日期：";
        Date::print();
        cout<<"出生孩子的名字："<<Childname<<endl;
    }
};
//iii.设计主程序显示一个小孩的出生时间和名字。
int main()
{
    Birthtime b(12,12,12,2012,12,12,"小明");
    b.print();
    return 0;
}