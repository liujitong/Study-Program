#include<iostream>
#include<cstring>
using namespace std;
//设计一个mystring类
class mysting
{
    private:
    char *pstr;
    int length;
    public:
    //有参的构造函数
    mysting(char *str)
    {
        length=strlen(str);
        pstr=new char[length+1];
        strcpy(pstr,str);
    }
    //无参的构造函数
    mysting()
    {
        length=0;
        pstr=new char[length+1];
        strcpy(pstr,"");
    }
    //拷贝构造函数
    mysting(const mysting &x)
    {
        length=x.length;
        pstr=new char[length+1];
        strcpy(pstr,x.pstr);
    }
    //析构函数
    ~mysting()
    {
        delete []pstr;
    }

    //重载运算符
    //重载+=运算符
    mysting& operator+=(mysting &x)
    {
        length+=x.length;
        char *temp=new char[length+1];
        strcpy(temp,pstr);
        strcat(temp,x.pstr);
        delete []pstr;
        pstr=temp;
        return *this;
    }
    //重载=运算符
    mysting& operator=(mysting &x)
    {
        if(this==&x)
        {
            return *this;
        }
        delete []pstr;
        length=x.length;
        pstr=new char[length+1];
        strcpy(pstr,x.pstr);
        return *this;
    }
    //重载[]运算符
    char & operator[](int n)
	{
		static char ch=0;
		if(n<0 || n>=strlen(pstr))
		{
			cout<<"下标越界\n";
			return ch;
		}
		else
			return pstr[n];
	}

    //重载>>运算符
    friend istream& operator>>(istream &in,mysting &x);
    //重载<<运算符
    friend ostream& operator<<(ostream &out,mysting &x);
    //关系运算符重载声明友元
    friend bool operator==(mysting &x,mysting &y);
    friend bool operator!=(mysting &x,mysting &y);
    friend bool operator>(mysting &x,mysting &y);
    friend bool operator<(mysting &x,mysting &y);
    friend bool operator>=(mysting &x,mysting &y);
    friend bool operator<=(mysting &x,mysting &y);

};
istream& operator>>(istream &in,mysting &x)
{
    in>>x.pstr;
    x.length=strlen(x.pstr)+1;
    return in;
}
ostream& operator<<(ostream &out,mysting &x)
{
    out<<x.pstr;
    return out;
}
//重载所有关系运算符
bool operator==(mysting &x,mysting &y)
{
    if(strcmp(x.pstr,y.pstr)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator!=(mysting &x,mysting &y)
{
    if(strcmp(x.pstr,y.pstr)!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator>(mysting &x,mysting &y)
{
    if(strcmp(x.pstr,y.pstr)>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator<(mysting &x,mysting &y)
{
    if(strcmp(x.pstr,y.pstr)<0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator>=(mysting &x,mysting &y)
{
    if(strcmp(x.pstr,y.pstr)>=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator<=(mysting &x,mysting &y)
{
    if(strcmp(x.pstr,y.pstr)<=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    mysting str1("hello");
    mysting str2("world");
    mysting str3;
    cin>>str3;
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    str3+=str1;
    cout<<str3<<endl;
    if(str1==str2)
    {
        cout<<"str1==str2"<<endl;
    }
    else
    {
        cout<<"str1!=str2"<<endl;
    }
    if(str1>str2)
    {
        cout<<"str1>str2"<<endl;
    }
    else
    {
        cout<<"str1<str2"<<endl;
    }
    if(str1>=str2)
    {
        cout<<"str1>=str2"<<endl;
    }
    else
    {
        cout<<"str1<=str2"<<endl;
    }
    cout<<str1[3]<<endl;
    return 0;
}
