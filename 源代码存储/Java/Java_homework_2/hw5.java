package 源代码存储.Java.Java_homework_2;

public class hw5 {
    public static void main(String[] args) {
        int m=1;
        int[] n=new int[2];
        try{
            n[2]=m/1;
        }catch(ArithmeticException e1){
            System.out.println("异常了"+e1.getMessage());
        }catch(ArrayIndexOutOfBoundsException e2){
            System.out.println("捕获到数组越界"+e2.getMessage());
        }finally{
            System.out.println("程序结束");
        }
    }
}
