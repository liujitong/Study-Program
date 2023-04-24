#include<iostream>
using namespace std;
class Animal
{
    public:
    virtual void Sound()=0;
};
class Cat:public Animal
{
    public:
    void Sound()
    {
        cout<<"喵喵喵"<<endl;
    }
};
class Leopard:public Animal
{
    public:
    void Sound()
    {   
        cout<<"啊！"<<endl;
    }
};
int main()
{
    Animal *p;
    Cat c;
    Leopard l;
    p=&c;
    p->Sound();
    p=&l;
    p->Sound();
    return 0;
}