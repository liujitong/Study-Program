#include<bits/stdc++.h>
#include<stdio.h>
#include<malloc.h>
using namespace std;
struct  Haffman
{
    /* data */
    char data;
    int freq;
    Haffman* left;
    Haffman* right;
    Haffman(){}
    Haffman(char data1,int freqc) :data(data1),freq(freqc){
    }
};
struct cmp//用于定义优先队列,虽然我不理解，但文档就这么写的，我也不知道咋搞，还说可以在一个类里面用static
{
    bool operator() (Haffman* A,Haffman* B)
    {
        return A->freq > B->freq;
    }
};
Haffman* Haffmaninit(vector<char> data,vector<int> fre)
{
    priority_queue<Haffman*,vector<Haffman*>,cmp> ls;//哈夫曼构造的优先队列
    for(int i =0;i<(int)(data.size());i++)
    {
        //将哈夫曼各节点插入优先队列中去
        Haffman* newH=new Haffman();//创建节点
        newH->data=data[i];
        newH->freq=fre[i];
        newH->left=nullptr;
        newH->right=nullptr;
        ls.push(newH);
    }
    while(ls.size()>1)//当优先队列成为一个结点时候，代表已经转换成为一个二叉树，参考哈夫曼树的构建
    {
        //根据哈夫曼树的构建原则，取两个最值作为左右子树
        Haffman *leftH=ls.top();
        ls.pop();
        Haffman *rightH=ls.top();
        ls.pop();
        Haffman *pNode=new Haffman('\0',leftH->freq+rightH->freq);//初始化父类节点
        pNode->left=leftH;
        pNode->right=rightH;
        ls.push(pNode);
    }
    return ls.top();
}
void printHaffman(Haffman* root,string code="")//最后会返回一个
{
    if(root==nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {//输出叶子结点的权值大小
        cout << root->data << ": " << code << endl;
    }
    //左子树和右子树递归
    printHaffman(root->left,code+"0");//左加零
    printHaffman(root->right,code+"1");//右加一
}


void FloorPrint_QUEUE(Haffman* Tree) //层序遍历_队列实现
{
    queue < Haffman* > q;
    if (Tree != NULL)
        q.push(Tree);   //根节点进队列
    while (q.empty() == false)  //队列不为空
    {
        Haffman* node=q.front();
        cout << "(数值："<<node->data<<" 权:"<<node->freq<<")"<<endl; 
 
        if (node->left != NULL)   //如果有左孩子，入队
            q.push(node->left);   
 
        if (node->right != NULL)   //如果有右孩子，入队
            q.push(node->right);
        q.pop();  //已经遍历过的节点出队列
    }
}

int main()
{
    vector<char> data1;
    vector<int> fre;
    char da;
    int freq;
    cout << "请输入字符和对应的频率：(当频率输入权值小于等于0时跳出循环)" << endl;
    while(1)//死循环
    {
        
        cin>>da;
        cin>>freq;
        if(freq<=0) break;//频率是不可能小于0的，设置小于0时跳出循环
        data1.push_back(da);
        fre.push_back(freq);
    }
    Haffman *root=Haffmaninit(data1,fre);//初始化哈夫曼树

    //层序遍历输出哈夫曼树状结构
    FloorPrint_QUEUE(root);
    // 输出哈夫曼树中叶结点的哈夫曼编码
    cout << "哈夫曼编码如下：" << endl;
    printHaffman(root);
    return 0;
}