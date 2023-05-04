//1-4
#include<iostream>
using namespace std;
class example
{
    public:
    public:
	//无参（默认）构造函数
	example() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数
	example(int number01 ,int number02) {
		
		cout << "有参构造函数!" << endl;

		number1 = number01;
		number2 = new int(number02);
		
	}
	//拷贝构造函数  
	example(const example& p) {
		cout << "拷贝构造函数!" << endl;
		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
		number1 = p.number1;
		number2 = p.number2;
		
	}

	//析构函数
	~example() {
		cout << "析构函数!" << endl;
		if (number2 != NULL)
		{
			delete number2;
            number2=NULL;
		}
	}
    int number1;
    int *number2;
};

void test01()
{
	example p1(18, 180);

	example p2(p1);

	cout << "p1数一：" << p1.number1 << "数二" << *p1.number2 << endl;

	cout << "p1数一：" << p2.number1 << " 数二： " << *p2.number2 << endl;
}
int main()
{
    test01();
    return 0;
}