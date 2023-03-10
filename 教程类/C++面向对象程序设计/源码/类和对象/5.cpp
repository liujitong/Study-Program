///1-5
#include<iostream>
#include<string>
using namespace std;
class example1
{
    public:
    string exp1;
    example1()
    {
        cout<<"example1无参构造"<<endl;
    }
    //1有参构造函数
    example1(string name1)
    {
        exp1=name1;
        cout<<"example1 构造函数调用"<<endl;
    }
    //1析构函数
    ~example1()
    {
        cout<<"example1 析构函数调用"<<endl;
    }
};
class example2
{
    public:
    string exp2;

    example2()
    {
        cout<<"example2无参构造"<<endl;
    }
    //2有参构造函数
    example2(string name2 , string name3)
    {
        exp2=name2;
        ex1=name3;
        cout<<"example2构造函数调用"<<endl;
    }
    //2析构函数
    ~example2()
    {
        cout<<"example2析构函数调用"<<endl;
    }
    void print()
    {
        cout<<"1内容"<<ex1.exp1<<"2内容"<<exp2<<endl;
    }
    example1 ex1;
};
void test01()
{
    //当类中成员是其他类对象时，我们称该成员为 对象成员
	//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
	//析构顺序与构造相反
    example2 exp3("ljt","ljx");
    exp3.print();
}
int main()
{
    test01();
    return 0;
}