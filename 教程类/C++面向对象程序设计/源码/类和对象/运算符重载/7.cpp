//运算符重载-7
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
        bool operator== (example x)
        {
            cout<<"重载==运算符"<<endl;
            if(a==x.a&&b==x.b)
                return true;
            else
                return false;
        }
        bool operator!= (example x)
        {
            cout<<"重载!=运算符"<<endl;
            if(a!=x.a||b!=x.b)
                return true;
            else
                return false;
        }
        bool operator> (example x)
        {
            cout<<"重载>运算符"<<endl;
            if(a>x.a&&b>x.b)
                return true;
            else
                return false;
        }
        bool operator< (example x)
        {
            cout<<"重载<运算符"<<endl;
            if(a<x.a&&b<x.b)
                return true;
            else
                return false;
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
    if(e1==e2)
        cout<<"e1==e2"<<endl;
    else
        cout<<"e1!=e2"<<endl;
    if(e1!=e2)
        cout<<"e1!=e2"<<endl;
    else
        cout<<"e1==e2"<<endl;
    if(e1>e2)
        cout<<"e1>e2"<<endl;
    else
        cout<<"e1<=e2"<<endl;
    if(e1<e2)
        cout<<"e1<e2"<<endl;
    else
        cout<<"e1>=e2"<<endl;
    return 0;
}