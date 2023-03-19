#include<iostream>
#include<string>
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
    Date(const Date& p){
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
     void display() const{
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }
};
class Student{
private:
    int id;         // 学号
    string name;    // 姓名
    string gender;  // 性别
    Date birthday;  // 出生日期
public:
    // 无参构造函数
    Student() {
        id = 0;
        name = "";
        gender = "";
        birthday = Date();
    }
    //有参构造函数
    Student(int i,string n,string g,int y, int m,int d):id(i),name(n),gender(g),birthday(y,m,d){}
    //拷贝构造函数
    Student(const Student& stu){
        id=stu.id;
        name= stu.name;
        gender = stu.gender;
        birthday =stu.birthday;
    }
    //析构函数
    ~Student(){}
    // 设置学号
    void setId(int i) {
        id = i;
    }
    // 获取学号
    int getId() const {
        return id;
    }
    // 设置姓名
    void setName(string n) {
        name = n;
    }
    // 获取姓名
    string getName() const {
        return name;
    }
    // 设置性别
    void setGender(string g) {
        gender = g;
    }
    // 获取性别
    string getGender() const {
        return gender;
    }
    // 设置出生日期
    void setBirthday(int y, int m, int d) {
        birthday.setYear(y);
        birthday.setMonth(m);
        birthday.setDay(d);
    }

    // 获取出生日期
    Date getBirthday() const {
        return birthday;
    }

    // 输出学生信息
    void display() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Birthday: ";
        birthday.display();
    }
};

int main(){
    Student stu1(10,"ljx","男",2004,05,01);
    stu1.display();
    Student stu2;
    stu2.setId(10083);
    stu2.setName("陈");
    stu2.setGender("女");
    stu2.setBirthday(2008,07,01);
    stu2.display();
    Student stu3(stu1);
    stu3.display();

}