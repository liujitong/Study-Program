package 源代码存储.Java.Java_homework_1;

public class hw8 {
    public static void main(String[] args) {
        mailcode mailcode1=new mailcode();
        try{
            mailcode1.set_mailcode("15000");
        }catch(IllegalArgumentException e1){
            System.out.println("捕获到一个异常"+":"+e1.getMessage());
        }finally{
            System.err.println("异常捕获程序结束了");
        }
    }
}
