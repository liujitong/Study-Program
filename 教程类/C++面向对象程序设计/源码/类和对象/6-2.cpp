//1-6-2
#include<iostream>
using namespace std;
class example
{

public:

	//静态成员函数特点：
	//1 程序共享一个函数
	//2 静态成员函数只能访问静态成员变量
	
	static void func()
	{
		cout << "func调用" << endl;
		a= 100;
		//b = 100; //错误，非静态成员引用必须与特定对象相对
	}

	static int a; //静态成员变量
	int b; // 
    private:

        //静态成员函数也是有访问权限的
    static void func2()
    {
        cout << "func2调用" << endl;
    }
};
int example::a = 10;


int main()
{
    //访问方式两种
    example::func();
    example exp1;
    exp1.func();
    //example::func2(); 函数 "example::func2" (已声明 所在行数:24) 不可访问
}