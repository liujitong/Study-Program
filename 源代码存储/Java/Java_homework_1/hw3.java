package 源代码存储.Java.Java_homework_1;

import java.util.Scanner;

public class hw3 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int[] Array=new int[3];
        int i;
        i=sc.nextInt();        
        sc.close();
        try
        {
            if(i>Array.length) throw new ArrayIndexOutOfBoundsException("您的数组越界了");
        }catch(ArrayIndexOutOfBoundsException A1){
            System.out.println(A1.getMessage());
            System.out.println("数组越界异常");
        }
        finally{
            System.out.println("程序结束");
        }
        
    }
}
