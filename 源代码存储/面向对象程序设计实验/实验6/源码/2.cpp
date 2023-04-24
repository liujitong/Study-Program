#include<iostream>
#include<cstdlib>
using namespace std;
//一维数组的排序，查找，求和
template <typename T>
class Array 
{
 public:
  T add(T array[]);
  bool search(T array[],T s);
  void sort(T array[]);
};
//类外定义
template <typename T>
T Array<T>::add(T array[])
{
  T sum=0;
  for(int i=0;i<10;i++)
    sum+=array[i];
  return sum;
}

template <typename T>
bool Array<T>::search(T array[],T s)
{
  for(int i=0;i<10;i++)
    if(array[i]==s)
      return true;
  return false;
}

template <typename T>

void Array<T>::sort(T array[])
{
  for(int i=0;i<10;i++)
    for(int j=i+1;j<10;j++)
      if(array[i]>array[j])
    {
      T temp=array[i];
      array[i]=array[j];
      array[j]=temp;
    }
}
int main()
{
    Array<int> a;
    int array[10];
    for(int i=0;i<10;i++)
        array[i]=rand()%100;
    cout<<"原数组为："<<endl;
    for(int i=0;i<10;i++)
        cout<<array[i]<<" ";
    cout<<endl;
    cout<<"数组求和为："<<a.add(array)<<endl;
    a.sort(array);
    cout<<"排序后的数组为："<<endl;
    for(int i=0;i<10;i++)
        cout<<array[i]<<" ";
    cout<<endl;
    int s;
    cout<<"请输入要查找的数：";
    cin>>s;
    if(a.search(array,s))
        cout<<"找到了"<<endl;
    else
        cout<<"没找到"<<endl;
    return 0;
}