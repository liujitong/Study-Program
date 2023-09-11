import java.util.Scanner;
public class l1 {
public static void main(String[] args) 
{
    Scanner sc= new Scanner(System.in);
    int[] al=new int[6];
    for(int i=0;i<6;i++)
    {
        al[i]=sc.nextInt();
    }
    for(int aw:al)
    {
        System.out.println(aw);
    }
    sc.close();
}
}
