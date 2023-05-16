#include<iostream>
using namespace std;
//定义复数类
class complex
{
    public:
    //有参的构造函数
    complex(double r,double i)
    {
        real=r;
        image=i;
    }
    //无参的构造函数
    complex()
    {
        real=0;
        image=0;
    }
    //拷贝构造函数
    complex(const complex &x)
    {
        real=x.real;
        image=x.image;
    }
    ~complex(){};
    //重载运算符
    complex operator+(complex &x)
    {
        complex temp;
        temp.real=real+x.real;
        temp.image=image+x.image;
        return temp;
    }
     complex operator-(complex &x)
    {
        complex temp;
        temp.real=real-x.real;
        temp.image=image-x.image;
        return temp;
    }
    //前置自增运算符
    complex& operator++()
    {
        real++;
        image++;
        return *this;
    }
    //后置自增运算符
    complex operator++(int)
    {
        complex temp;
        temp.real=real++;
        temp.image=image++;
        return temp;
    }
    //前置自减运算符
    complex& operator--()
    {
        real--;
        image--;
        return *this;
    }
    //后置自减运算符
    complex operator--(int)
    {
        complex temp;
        temp.real=real--;
        temp.image=image--;
        return temp;
    }
    //重载输出运算符
    friend ostream& operator<<(ostream &out,complex &x)
    {
        if(x.image>0) out<<x.real<<"+"<<x.image<<"i"<<endl;
        if(x.image<0) out<<x.real<<x.image<<"i"<<endl;
        return out;
    }
    //重载输入运算符
    friend istream& operator>>(istream &in,complex &x)
    {
        char s;
        char i;
        in>>x.real>>s>>x.image>>i;
        if(s=='-') x.image=-x.image;
        return in;
    }
    friend complex operator-(complex &x);
    private:
    double real;
    double image;
};
int main()
{
    complex a(1,2),b(3,4),c,d;
    c=a+b;
    cout<<c;
    c=a-b;
    cout<<c;
    c=++a;
    cout<<c;
    c=a++;
    cout<<c;
    c=--a;
    cout<<c;
    c=a--;
    cout<<c;
    cout<<"开始测试输入1"<<endl;
    cin>>c;
    cout<<c;
    cout<<"开始测试输入2"<<endl;
    cin>>c>>d;
    cout<<c<<d;
    return 0;
}