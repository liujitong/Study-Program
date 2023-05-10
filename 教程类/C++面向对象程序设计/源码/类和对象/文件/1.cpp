//文件-1（文本文件写入）
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream ofs1;
   ofs1.open("1.txt",ios::out);
   ofs1<<"我是你的爸爸"<<endl;
   ofs1<<"66666"<<endl;
   ofs1.close();
}