#include<iostream>
using namespace std;
class Vehicle
{
    public:
    virtual void printinfo()
    {
        cout<<"这是一辆车"<<endl;
    };
};
class Car:public Vehicle
{
    public:
    void printinfo()
    {
        cout<<"这是一辆小汽车"<<endl;
    }
};
class Truck:public Vehicle
{
    public:
    void printinfo()
    {
        cout<<"这是一辆卡车"<<endl;
    }
};
class boat:public Vehicle
{
    public:
    void printinfo()
    {
        cout<<"这是一艘船"<<endl;
    }
};
int main()
{
    Vehicle *p;

    Car c;
    Truck t;
    boat b;
    p=&c;
    p->printinfo();
    p=&t;
    p->printinfo();
    p=&b;
    p->printinfo();
    return 0;
}