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
int main()
{
	point p1,p2;
	p1.setxy(0,0);
	p2.setxy(1,1);
	line l12(p1,p2);
	cout<<l12.getlen()<<endl;
	return 0;
}
