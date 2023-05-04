//1-3
#include<iostream>
using namespace std;
class example 
{
    public:
	//无参（默认）构造函数
	example() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数
	example(int a) {
    	number = a;
		cout << "有参构造函数!" << endl;
	}
	//拷贝构造函数
	example(const example& p) {
        number = p.number;
		cout << "拷贝构造函数!" << endl;
	}
	//析构函数
	~example() {
		cout << "析构函数!" << endl;
	}

    int number;
};
/*
void test01()
{
	example p1(18);
	//如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
	example p2(p1);

	cout << "这个数字是 " << p2.number << endl;
}
*/
void test02()
{
    
	//如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造
	example p1; //此时如果用户自己没有提供默认构造，会出错
	example p2(10); //用户提供的有参
	example p3(p2); //此时如果用户没有提供拷贝构造，编译器会提供

	//如果用户提供拷贝构造，编译器不会提供其他构造函数
	example p4; //此时如果用户自己没有提供默认构造，会出错
	example p5(10); //此时如果用户自己没有提供有参，会出错
	example p6(p5); //用户自己提供拷贝构造

}
int main()
{
    test02();
    return 0;
}