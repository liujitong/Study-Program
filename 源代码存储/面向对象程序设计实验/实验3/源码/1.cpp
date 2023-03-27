
#include<iostream>
using namespace std;
//i. 定义一个基类圆，至少含有一个数据成员半径；
class circle
{
protected:
    double r;
public:
    circle(double r1)
    {
        r=r1;
    }
    double getr()
    {
        return r;
    }
};
//ii. 定义基类的派生类球、圆柱、圆锥，都含有求体积的成员函数和输出函数。
class ball:public circle
{
public:
    ball(double r1):circle(r1)
    {
    }
    double getv()
    {
        return 4/3*3.14*r*r*r;
    }
    void print()
    {
        cout<<"球的体积为："<<getv()<<endl;
    }
};
class cylinder:public circle
{
protected:
    double h;
public:
    cylinder(double r1,double h1):circle(r1)
    {
        h=h1;
    }
    double getv()
    {
        return 3.14*r*r*h;
    }
    void print()
    {
        cout<<"圆柱的体积为："<<getv()<<endl;
    }
};
class cone:public circle
{
protected:
    double h;
public:
    cone(double r1,double h1):circle(r1)
    {
        h=h1;
    }
    double getv()
    {
        return 1/3*3.14*r*r*h;
    }
    void print()
    {
        cout<<"圆锥的体积为："<<getv()<<endl;
    }
};
//iii. 定义主函数，求球、圆柱、圆锥的体积。
int main()
{
    ball b(2);
    b.print();
    cylinder c(2,3);
    c.print();
    cone co(2,3);
    co.print();
    return 0;
}

