package 源代码存储.Java.实验4.CODE;

import java.util.Scanner;

public class AnimalTest {
    public static void main(String[] args) {
        Animal animallist[]=new Animal[6];
        Scanner sc=new Scanner(System.in);
        
        String str1;
        String str2;
        String str3;
        int xx;
        //猫
        for(int i=0;i<3;i++)
        {
            System.out.println("请输入第"+(i+1)+"只猫的信息（顺序为：type name color age）");
            str1=sc.next();
            str2=sc.next();
            str3=sc.next();
            xx=sc.nextInt();
            animallist[i]=new Cat(str1,str2,str3,xx);
        }
        //马
        for(int i=0;i<3;i++)
        {
            System.out.println("请输入第"+(i+1)+"只马的信息（顺序为：type name color height）");
            str1=sc.next();
            str2=sc.next();
            str3=sc.next();
            xx=sc.nextInt();
            animallist[3+i]=new Horse(str1,str2,str3,xx);
        }
        for(int i=0;i<6;i++)
        {
            System.out.println(animallist[i]);
            animallist[i].walk();
            animallist[i].wakeUp();
        }
        sc.close();
    }
}
