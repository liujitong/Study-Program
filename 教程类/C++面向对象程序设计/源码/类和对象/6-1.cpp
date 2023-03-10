//1-6-1 静态成员变量
#include<iostream>
using namespace std;
class example{
    public:
    static int a;//静态成员变量是共享的，类内声明，类外初始化，所有对象都可以访问这个数据
    private:
    static int b;//静态成员变量也是可以有访问权限的
};
int example::a = 10;
int example::b = 10;
int main()
{
    cout<<example::a<<endl;
    //第一种访问方式
    example::a = 60;
    cout<<example::a<<endl;
    //第二种
    example exp1;
    example exp2;
    exp1.a=20;
    cout<<"类"<<example::a<<endl;
    cout<<"exp1:"<<exp1.a<<endl;
    cout<<"exp2:"<<exp2.a<<endl;
    exp2.a =30;
    cout<<"类"<<example::a<<endl;
    cout<<"exp1:"<<exp1.a<<endl;
    cout<<"exp2:"<<exp2.a<<endl;
    //cout<<"b的值"<<endl;
    //cout<<example::b<<endl; 报错：成员 \"example::b\" (已声明 所在行数:11) 不可访问
    return 0;
}