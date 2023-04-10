//运算符重载-3
#include<iostream>
using namespace std;
class example
{
    public:
        int a;
        int b;
        example(int x,int y):a(x),b(y)
        {
            cout<<"初始化赋值操作"<<endl;
        }
        //如果需要访问私有成员，需要将重载运算符函数声明为友元函数
        friend ostream& operator<< (ostream &out,example x);
};
ostream& operator<< (ostream &out,example x)
{
    cout<<"重载<<运算符"<<endl;
    out<<x.a<<","<<x.b<<endl;
    return out;
}
int main()
{
    example e1(1,2),e2(3,4);
    cout<<e1<<e2;
    return 0;
}