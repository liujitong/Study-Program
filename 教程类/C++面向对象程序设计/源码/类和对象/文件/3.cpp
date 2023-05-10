//文件-3（二进制写入）
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream ofs1;
    ofs1.open("erjinzhi",ios::out|ios::binary);
    string p="7";
    ofs1.write((const char *)&p,sizeof(p));
    ofs1.close();
}