package 源代码存储.Java.学习.Test1;

public class Lighterr extends Exception{
    public Lighterr(int ID)
    {
        super("编号为"+ID+"的灯坏了");
    }
}
