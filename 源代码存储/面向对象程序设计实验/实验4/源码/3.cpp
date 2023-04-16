#include<iostream>
using namespace std;
class shape
{
    public:
    virtual void printinfo()=0;
    //公有的计算面积area函数
    virtual void area()=0;
    //计算体积volume函数
    virtual void volume()=0;
};
class point:public shape
{
    public:
    //构造函数，析构函数
    point(int a,int b)
    {
        x=a;
        y=b;
    }
    ~point(){};
    //公有的计算面积area函数
    void printinfo()
    {
        cout<<"这是一个点"<<endl;
    }
    void area()
    {
        cout<<"面积为0"<<endl;
    }
    void volume()
    {
        cout<<"体积为0"<<endl;
    }
    //私有数据成员x,y坐标
    private:
    int x,y;
};
//从point公有派生circle类
class circle:public point
{
    public:
    //构造函数，析构函数
    circle(int a,int b,int c):point(a,b)
    {
        r=c;
    }
    ~circle(){};
    //公有的计算面积area函数
    void printinfo()
    {
        cout<<"这是一个圆"<<endl;
    }
    void area()
    {
        cout<<"面积为"<<3.14*r*r<<endl;
    }
    void volume()
    {
        cout<<"体积为0"<<endl;
    }
    //私有数据成员r半径
    protected:
    int r;
};
class cylinder : public circle
{
    //增加私有数据成员高度h
    private:
    int h;
    //构造函数，析构函数
    public:
    cylinder(int a,int b,int c,int d):circle(a,b,c)
    {
        h=d;
    }
    ~cylinder(){};
    //公有的计算面积area函数
    void printinfo()
    {
        cout<<"这是一个圆柱体"<<endl;
    }
    void area()
    {
        cout<<"面积为"<<2*3.14*r*r+2*3.14*r*h<<endl;
    }
    void volume()
    {
        cout<<"体积为"<<3.14*r*r*h<<endl;
    }
};
//在main函数中，定义shape类的指针，指向派生类的对象，输出三类对象的基本信息，面积，体积；
int main()
{
    shape *p;
    point a(1,2);
    circle b(1,2,3);
    cylinder c(1,2,3,4);
    p=&a;
    p->printinfo();
    p->area();
    p->volume();
    p=&b;
    p->printinfo();
    p->area();
    p->volume();
    p=&c;
    p->printinfo();
    p->area();
    p->volume();
    return 0;
}