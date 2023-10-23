package 源代码存储.Java.学习.Test1;
public class main {
    public static void main(String[] args) {
         Light L1[]=new Light[10];
         for(int i=0;i<4;i++)//4个不亮的
         {
            L1[i]=new Light(0);
            L1[i].set_ID(i);
         }
         for(int i=4;i<9;i++)//四个亮
         {
            L1[i]=new Light(1);
            L1[i].set_ID(i);       
        }
        L1[9]=new Light(-1);//一个坏的
        L1[9].set_ID(9);
        for(int i=0;i<10;i++)
        {
        try
        {
            L1[i].press_switch();
        }catch (Lighterr l1)
        {
            System.err.println(l1.getMessage());
            System.out.println("灯坏了，上报管理处");
        }
        }
    }    
}
