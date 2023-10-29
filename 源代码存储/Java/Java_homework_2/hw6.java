package 源代码存储.Java.Java_homework_2;

public class hw6 {

    public static void main(String[] args) {
        try{
            int m=2/0;
            System.out.println(m);//这块虽然，没有什么实际作用，但是可以起到消除Warning的效果
        }catch(ArithmeticException e2){
            System.out.println("捕获到算术异常"+e2.getMessage());
        }
        catch(Exception e2){
            System.out.println("捕获到其他异常"+e2.getMessage());
        }
        finally{
            System.out.println("异常捕获语句结束");
        }
    }
}
