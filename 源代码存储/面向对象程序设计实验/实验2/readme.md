# 实验2 类与对象

## 实验目的

- 理解概念：类的构造函数、拷贝构造函数、析构函数。
- 理解类的构造函数和析构函数的作用及运行机制。
- 掌握构造函数、拷贝构造函数和析构函数的定义及应用。
- 理解类的组合关系，并掌握类组合关系的实现。

## 实验学时

本次实验需要2个学时。

## 实验要求

- 实验上机之前，根据实验内容要求，自行设计编写程序，完成预习报告。
- 实验上机时调试并修正程序。
- 当次上机结束前分析错误原因并给出实验结论，提交实验报告。

## 实验内容

### 1.基础部分

- （1）定义一个日期类Date，包括月、日、年3个私有数据成员，函数成员包括公有的构造函数（包括带参构造函数，无参构造函数）、拷贝构造函数和析构函数、设置数据成员和获取数据成员等函数；在main函数中定义Date类的对象，对其进行初始化、修改和输出。（可自行增加需要的成员函数）

- （2）定义学生类Student，包括一些基本信息如学号，姓名，性别，出生日期属于日期类Date型（利用第（1）题的Date类），函数成员包括公有的构造函数（包括带参构造函数，无参构造函数）、拷贝构造函数和析构函数、设置数据成员和获取数据成员等函数；在main函数中定义Student类的对象，对其进行初始化、修改和输出。（这是组合类的问题。请使用构造函数实现对象成员的初始化。可自行增加需要的成员函数）

### 2.进阶部分

- （3）利用第(1)题和第(2)题中定义的Date类和Student类，在main函数中定义班级通讯录（可用Student类的对象数组实现，数组元素个数可以定义符号常量），并添加本班同学和显示同学信息。

- （4）读程序写结果。注：这是一个组合类的问题。点类point的两个对象组合成了line类。线类的构造函数实现了对象成员p1、p2的初始化。

```C++
#include <iostream>
#include<string>
#include<cmath>
using namespace std;
class point
{
private:
	int x;
	int y;
	void setx(int xx)
	{
		x=xx;
	}
	void sety(int yy)
	{
		y=yy;
	}
public:
//下面这段被注释掉的无参构造函数，如果去掉注释，会怎么样？分析原因。
	/*point()
	{
		x=0;
		y=0;
	}*/
	point(int xx=0,int yy=0);
	point(const point&pt)
	{
		x=pt.x;
		y=pt.y;
		cout<<"copy constructor..."<<endl;
	}
	void setxy(int xx,int yy)
	{
		setx(xx);
		sety(yy);
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	void showpoint()
	{
		cout<<"x="<<x<<",y="<<y<<endl;
	}
	~point()
	{
		cout<<"point des..."<<endl;
	}
};
inline point::point(int xx,int yy)
{
	x=xx;
	y=yy;
	cout<<"constructor..."<<endl;
}
class line
{
private:
	point p1,p2;
public:
	line(point &tp1,point &tp2):p1(tp1),p2(tp2)
	{
		cout<<"line cons..."<<endl;
	}
	line(line & ltemp)
	{
		p1=ltemp.p1;
		p2=ltemp.p2;
		cout<<"line copy cons..."<<endl;
	}
	double getlen()
	{
		return sqrt(pow(p1.getx()-p2.getx(),2)+pow(p1.gety()-p2.gety(),2));
	}
	~line()
	{
		cout<<"line des..."<<endl;
	}
};
void main()
{
	point p1,p2;
	p1.setxy(0,0);
	p2.setxy(1,1);
	line l12(p1,p2);
	cout<<l12.getlen()<<endl;
}
```
