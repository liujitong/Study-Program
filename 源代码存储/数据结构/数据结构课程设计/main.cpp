//头文件
#include<iostream> // 输入输出流
#include<cstring> // 字符串操作
#include<fstream> // 文件操作
using namespace std;
//结构文件

typedef struct good
{
    string name; // 商品名称
    string brand; // 商品品牌
    int num; // 商品数量
    float price; // 商品价格
    struct  good *next; // 下一个商品节点指针
}goods;

// 向链表中插入商品节点，按照单价的升序排列链表
void insert(goods *head, const string& name, const string& brand, int num, float price)
{
    goods *p,*q;
    p=head;
    while(p->next!=NULL)
    {
        if(p->next->price>price)
        {
            break;
        }
        p=p->next;
    }
    q=new goods;
    q->name = name;
    q->brand = brand;
    q->num=num;
    q->price=price;
    q->next=p->next;
    p->next=q;
}

// 更新链表中指定商品的数
void update(goods *head, const string& name, int num)
{
    goods *p;
    p=head->next;
    while(p!=NULL)
    {
        if(p->name==name)
        {
            p->num=num;
            break;
        }
        //如果数量为0，删除节点
        if(p->num==0)
        {
            goods *q;
            q=p->next;
            p->next=q->next;
            delete q;
        }
        p=p->next;
    }
}
//利用数据域中的name来对品牌或者价格，或者两者都更新，通过调用update_brand和update_price进行更新。
void update_brand(goods *head, const string& name, const string& brand)
{
    goods *p;
    p=head->next;
    while(p!=NULL)
    {
        if(p->name==name)
        {
            p->brand=brand;
            break;
        }
        p=p->next;
    }
}
void update_price(goods *head, const string& name, float price)
{
    goods *p;
    p=head->next;
    while(p!=NULL)
    {
        if(p->name==name)
        {
            p->price=price;
            break;
        }
        p=p->next;
    }
}
// 按名称查找商品信息
void search_name(goods *head, const string& name)
{
    goods *p;
    p=head->next;
    while(p!=NULL)
    {
        if(p->name==name)
        {
            system("cls");
            cout<<"商品名称："<<p->name<<endl;
            cout<<"商品品牌："<<p->brand<<endl;
            cout<<"商品数量："<<p->num<<endl;
            cout<<"商品价格："<<p->price<<endl;
            system("pause");
            break;
        }
        p=p->next;
    }
}

// 按品牌查找商品信息
void search_brand(goods *head, const string& type)
{
    goods *p;
    p = head->next;
    while (p != NULL)
    {
        if (p->brand == type)
        {
            cout << "商品名称：" << p->name << endl;
            cout << "商品品牌：" << p->brand << endl;
            cout << "商品数量：" << p->num << endl;
            cout << "商品价格：" << p->price << endl;
        }
        p = p->next;
    }
}
//遍历
void traverse(goods *head)
{
    goods *p;
    p=head->next;
    while(p!=NULL)
    {
        cout<<"商品名称："<<p->name<<endl;
        cout<<"商品品牌："<<p->brand<<endl;
        cout<<"商品数量："<<p->num<<endl;
        cout<<"商品价格："<<p->price<<endl;
        p=p->next;
    }
}
// 每日开始营业之前，需将以文件形式保存的数据恢复成链表结构的有序表。
void create_head(goods *head) // 创建链表
{
    ifstream fin("goods.txt");
    if(!fin)
    {
        cout<<"文件打开失败！"<<endl;
        exit(0);
    }
    char name[20];
    char brand[20];
    int num;
    float price;
    while(fin>>name>>brand>>num>>price)
    {
        insert(head,name,brand,num,price);
    }
    fin.close();
}

// 结束营业，将链表中的数据写入文件
void end(goods *head)
{
    ofstream fout("goods.txt");
    if(!fout)
    {
        cout<<"文件打开失败！"<<endl;
        exit(0);
    }
    goods *p;
    p=head->next;
    while(p!=NULL)
    {
        fout<<p->name<<" "<<p->brand<<" "<<p->num<<" "<<p->price<<endl;
        p=p->next;
    }
    fout.close();
}

int main()
{
    goods *head;
    head=new goods;
    head->next=NULL;
    create_head(head);
    int choice;
    char name[20];
    char brand[20];
    int num;
    float price;
    char type[20];
    while(1)
    {
        system("cls");
        cout<<"1.录入商品信息"<<endl;
        cout<<"2.修改商品信息"<<endl;
        cout<<"3.查询商品信息"<<endl;
        cout<<"4.结束营业"<<endl;
        cout<<"请输入您的选择：";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"请输入商品名称：";
                cin>>name;
                cout<<"请输入商品品牌：";
                cin>>brand;
                cout<<"请输入商品数量：";
                cin>>num;
                cout<<"请输入商品价格：";
                cin>>price;
                insert(head,name,brand,num,price);
                break;
            case 2:
                cout<<"请输入商品名称：";
                cin>>name;
                cout<<"请输入商品数量：";
                cin>>num;
                update(head,name,num);
                break;
            case 3:
                cout<<"1.按名称查询"<<endl;
                cout<<"2.按品牌查询"<<endl;
                cout<<"请输入您的选择：";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        cout<<"请输入商品名称：";
                        cin>>name;
                        search_name(head,name);
                        break;
                    case 2:
                        cout<<"请输入商品品牌：";
                        cin>>type;
                        search_brand(head,type);
                        break;
                    default:
                        cout<<"输入错误！"<<endl;
                        break;
                }
                break;
            case 4:
                end(head);
                exit(0);
            default:
                cout<<"输入错误！"<<endl;
                break;
        }
    }
}