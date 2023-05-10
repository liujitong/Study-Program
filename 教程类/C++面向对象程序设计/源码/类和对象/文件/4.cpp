//文件-3（二进制读取）
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream ifs1;
    ifs1.open("erjinzhi",ios::in|ios::binary);
   	if (!ifs1.is_open())
	{
		cout << "文件打开失败" << endl;
		return 0;
	}
    char *p;
    ifs1.read((char *)&p, 1024);
    cout<<p<<endl;
    ifs1.close();
}