#include<iostream>
using namespace std;
class example
{
    public:
    example()
    {
        a=0;
    }
    int a;
    example& func(int a)
    {
        this->a=a;
        return *this;
    }
    void print() const
    {
        cout<<a<<endl;
    }
    //void newfunc(int a) const
    //{
        //this->a=a;常函数不能修改成员变量
        //func(int a);常函数不能调用非常函数

    //}
};
int main()
{
    example ex;
    ex.func(10).func(20);
    ex.print();
    cout<<ex.a<<endl;
    const example ex2;
    //ex2.func(10);常对象只能调用常函数
    ex2.print();
}