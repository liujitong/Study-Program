package 源代码存储.Java.Java_homework_1;

import java.util.Random;
public class hw3 {
    public static void main(String[] args) {
    Random rd=new Random();
    char[] code=new char[4];
    for(int i=0;i<4;i++)
    {
        int type=rd.nextInt(2);
        if(type==0)
        {
            code[i]=(char)(rd.nextInt(10)+'0');
        }
        if(type==1)
        {
            if(rd.nextInt(2)==1) code[i]=(char)(rd.nextInt(24)+'A');
            else code[i]=(char)(rd.nextInt(24)+'a');
        } 
    }
    System.out.print(code);
    }
}
