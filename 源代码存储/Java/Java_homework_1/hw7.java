package 源代码存储.Java.Java_homework_1;

import java.util.Arrays;
import java.util.Random;

public class hw7 {
    public static void main(String[] args) {
        int[] nums=new int[10];
        Random rd=new Random();
        for(int i=0;i<10;i++)
        {  
            nums[i]=rd.nextInt(90)+10;
        }
        Arrays.sort(nums);
        for (int i=0;i<10;i++) {
            System.out.print(nums[i]+"  ");
        }
    }
}
