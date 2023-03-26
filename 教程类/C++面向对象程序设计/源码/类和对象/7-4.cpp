    //2-7-4
    #include<iostream>
    using namespace std;
    class example
    {
        public:
        int a;
        example& func(int a)
        {
            this->a=a;
            return *this;
        }
    };
    int main()
    {
        example* ex=NULL;
        ex->func(10).func(20);
        cout<<ex->a<<endl;
    }