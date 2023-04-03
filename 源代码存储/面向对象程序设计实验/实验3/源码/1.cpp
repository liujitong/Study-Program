
#include<iostream>
using namespace std;
//i. ����һ������Բ�����ٺ���һ�����ݳ�Ա�뾶��
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
//ii. ����������������Բ����Բ׶��������������ĳ�Ա���������������
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
        cout<<"������Ϊ��"<<getv()<<endl;
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
        cout<<"Բ�������Ϊ��"<<getv()<<endl;
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
        cout<<"Բ׶�����Ϊ��"<<getv()<<endl;
    }
};
//iii. ����������������Բ����Բ׶�������
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

