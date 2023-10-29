package 源代码存储.Java.Java_homework_2;

public class hw7 {
    public static void main(String[] args) {
  
      try {
        devision(0);
     }catch(ArithmeticException e1){
        System.out.println("算数异常"+e1.getMessage());
     }   
    }
    static void devision(int c) throws ArithmeticException
    {
            int a=100/c;
            System.out.println("100/c="+a);
    }
}
