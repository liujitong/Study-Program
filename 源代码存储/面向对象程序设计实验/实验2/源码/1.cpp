#include<iostream>
using namespace std;
class Date
{
private:
    int year;//年
    int day;//日
    int month;//月
public:
    //无参构造函数
    Date(){
        year = 1900;
        month = 1;
        day = 1;
    }
    //有参构造函数
    Date(int y,int m,int d){
        year=y;
        month=m;
        day=d;
    }
    //拷贝构造函数
    Date(const Date &p){
        year=p.year;
        day=p.day;
        month=p.month;
    }
    //析构函数
    ~Date(){

    }
     // 设置年份
    void setYear(int y) {
        year = y;
    }
    // 获取年份
    int getYear(){
        return year;
    }
    // 设置月份
    void setMonth(int m) {
        month = m;
    }
    // 获取月份
    int getMonth(){
        return month;
    }
    // 设置日期
    void setDay(int d) {
        day = d;
    }
    // 获取日期
    int getDay()  {
        return day;
    }
    // 输出日期
    void display(){
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }
};
int main()
{
    //声明一个
    Date Date1(2022,1,1);
    Date1.display();
    //修改
    Date1.setYear(2023);
    Date1.setMonth(3);
    Date1.setDay(19);
    //输出第一个
    Date1.display();
    //复制一个
    Date Date2 (Date1);
    Date2.display();
    system("pause");
    return 0;
}