# 实验1 C++基础编程

## 实验目的

-	掌握VC++ 6.0进行程序设计的基本步骤。

-	学会在VC++ 6.0环境下进行简单C++程序设计。

-	掌握new和delete的用法。

-	熟练使用string类处理字符串。

-	重点掌握函数的参数传递方式、函数重载、函数默认值的实现。

## 实验要求

-	实验上机之前，根据实验内容要求，自行设计编写程序，完成预习报告。

-	实验上机时调试并修正程序。

-	当次上机结束前分析错误原因并给出实验结论，提交实验报告。

## 实验内容

### 1.基础部分

（1）动态分配保存10个成绩数组的存储空间，并对成绩进行输入，求出最高分并输出，用new和delete。

（2）定义函数，实现两个变量的交换（用传递指针和传递引用的方式分别实现），并对比区别。

（3）定义函数求2个和3个整数的最大数。要求：用重载函数的方法来求最大数。函数原型：int max( int a, int b) 和 int max( int a, int b,int c)。

（4）上述第（3）题，如果希望使用内联函数提高程序效率，该如何修改？

### 2.进阶部分

（5）读程序，改正其中的错误，观察error的英文描述，总结相应知识点的使用方法,修改经验和注释方法。

```C++
#include <iostream>
int main()
{	//引用
	int i;
	int &r;//r引用i
	r=100;
	cout<<i<<endl;
	//命名常量
	const double fd;
	cout<<fd<<endl;
	//指向常量的指针
	int a=1,b=2;
	const int c=3;
	const int * pi;
	pi=&a;
	*pi=10;
	pi=&c;
	c=100;
	//常指针
	int * const pj;//pj指向a
	*pj=200;
	pj=&b;
	//指向常量的常指针
	const int * const pk;//pk指向b
	pk=&c;
	*pk=300;
	cout<<"a="<<a<<"b="<<b<<"c="<<c<<endl;
  return 0;
}
```
