package 源代码存储.Java.Java_homework_2;

import java.util.Scanner;

public class hw4 {
    public static void main(String[] args) {
        String class_inputs;
        Scanner sc=new Scanner(System.in);
        class_inputs=sc.next();
        sc.close();
        try{
            if(!class_inputs.equals("Person")) throw new ClassNotFoundException(class_inputs+"类未被发现");
        }catch(ClassNotFoundException e1){
            System.out.println(e1.getMessage());
            System.out.println("检测到类丢失异常");
        }finally{
            System.out.println("程序结束");
        }
    }
}
