//2-7-2
#include<iostream>
using namespace std;
class example
{
    public:
    void func(int a)
    {
        //this指针区分同名成员变量和形参
        this->a=a;
    }
    int a;
};
int main()
{
    example ex;
    ex.func(10);
    cout<<ex.a<<endl;
}