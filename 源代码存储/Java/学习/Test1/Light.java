package 源代码存储.Java.学习.Test1;
public class Light 
{
    int ID;//灯的编号。
    int status;//0代表关，1代表开，-1代表坏了
    public Light(int s)
    {
        status =s;
    }
    public Light()
    {
        status=0;
    }
    public void set_ID(int I)
    {
        ID=I;
    }
    public void press_switch () throws Lighterr
    {
        if(status==-1)  
        {
            throw new Lighterr(ID);//抛出异常
        }
        else if(status==0) 
        {
            status =1;
            System.out.println(ID+"灯亮了");
        }
        else if(status==1) 
        {
            status=0;
            System.out.println(ID+"灯灭了");
        }
    }
}