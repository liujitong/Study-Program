//运算符重载-6
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
        example operator= (example x)
        {
            cout<<"重载赋值运算符"<<endl;
            a=x.a;
            b=x.b;
            return *this;
        }
};
ostream& operator<<(ostream& out, example ex1) 
{
    out << ex1.a<<ex1.b;
    return out;
}
int main()
{
    example e1(1,2),e2(3,4);
    e1=e2;
    cout<<e1<<e2<<endl;
    return 0;
}