package 源代码存储.Java.Java_homework_2;
public class hw2 {
    public static void main(String[] args) {
        try{
            int[] MyArray=new int[-1];
            MyArray[-1]=-1;
        }catch(NegativeArraySizeException e1){
            System.out.println("发现数组负数异常："+e1.getMessage());
        }finally{
            System.out.println("程序结束");
        }
    }
}
