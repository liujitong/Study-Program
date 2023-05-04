//3-10
#include<iostream>
using namespace std;
class example1
{
    public:
    int a=1;
    protected:
    int b=2;
    private:
    int c=3;
};
class example2 :protected example1
{
    public:
    void print()
    {
        cout<<a<<endl;
        cout<<b<<endl;
        //cout<<c<<endl;//父类中的private成员变量和成员函数在子类中都是不可访问的
    }
};
class example3 :protected example2
{
    public:
    void print()
    {
        cout<<a<<endl;
        cout<<b<<endl;
        //cout<<c<<endl;//父类中的private成员变量和成员函数在子类中都是不可访问的
    }
};
int  main()
{
 example2 ex;
 //cout<<ex.a<<endl;//这显然是不可以的，因为私有继承，这个访问权限是protected的
 //cout<<ex.b<<endl;//同理，这个访问权限也是protected的
 //如example3 所示，protected继承，子类中的成员函数可以访问父类中的protected成员变量和成员函数
  ex.print();
    example3 ex2;
    ex2.print();//example3也可以访问到a,b说明protected继承的子类访问权限是protected
}