#include <iostream>
using namespace std;
int main()
{	//引用
	int i;
	int &r=i;//r引用i
	r=100;
	cout<<i<<endl;
	//命名常量
	const double fd=20;
	cout<<fd<<endl;
	//指向常量的指针
	int a=1,b=2;
	const int c=3;
	const int * pi;
	pi=&a;
	//*pi=10;
	pi=&c;
	//c=100;
	//常指针
	int * const pj= &a;//pj指向a
	*pj=200;
	//pj=&b;
	//指向常量的常指针
	const int * const pk=&b;//pk指向b
	//pk=&c;
	//*pk=300;
	cout<<"a="<<a<<"b="<<b<<"c="<<c<<endl;
  return 0;
}

