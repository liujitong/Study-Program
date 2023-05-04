//2-7-1
#include<iostream>
using namespace std;
class example
{
    //example构造函数
    example()
    {
        exp1=0;
        cout<<"example构造函数调用"<<endl;
    }
    //非静态成员变量占对象空间
    int exp1;
    //静态成员变量不占对象空间
    //static int exp2;
    //函数也不占对象空间，所有函数都是共享的。
    /*void func()
    {
        cout<<"func函数"<<endl;
    }
    //静态函数也是一样的
    static void func2()
    {
        cout<<"func函数"<<endl;
    }*/
};
int main()
{
    cout<<"类占空间"<<sizeof(example)<<endl;;
}