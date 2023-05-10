//文件-2（文本文件读取）
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream ifs1;
   ifs1.open("1.txt",ios::in);
   	if (!ifs1.is_open())
	{
		cout << "文件打开失败" << endl;
		return 0;
	}
    
	//第一种方式
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//第二种
	//char buf[1024] = { 0 };
	//while (ifs1.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//第三种
	//string buf;
	//while (getline(ifs1, buf))
	//{
	//	cout << buf << endl;
	//}

	char c;
	while ((c = ifs1.get()) != EOF)//EOF：end of file 
	{
		cout << c;
	}
   ifs1.close();
}