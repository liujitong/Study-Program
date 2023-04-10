//运算符重载-1
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
        example operator+ (example x)
        {
            cout<<"重载操作"<<endl;
            example temp(a+x.a,b+x.b);
            return temp;
        }
};
int main()
{
    example e1(1,2),e2(3,4);
    e1=e1+e1+e2+e2;
    example e3 = e1+e2;
    cout<<"e3的值";
    cout<<e3.a<<","<<e3.b<<endl;
    cout<<"e1的值";
    cout<<e1.a<<","<<e1.b<<endl;
    return 0;
}