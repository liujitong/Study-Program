//3-9
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
class example2 :private example1
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
 //cout<<ex.a<<endl;这显然是不可以的，因为私有继承，这个访问权限是private的
 //cout<<ex.b<<endl;同理，这个访问权限也是private的
  ex.print();
}