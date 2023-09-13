import java.util.Scanner;
public class No4 {
    public static void main(String[] args) {
        int[] day= new int[]{31,28,31,30,31,30,31,31,30,31,30,31};
        Scanner sc =new Scanner(System.in);
        int y;
        int m;
        int d;
        int days=0;
        y=sc.nextInt();
        m=sc.nextInt();
        d=sc.nextInt();
        if((y%4==0&&y%100!=0)||y%400==0)//判断闰年
        {
            day[1]=29;
        }
        for(int i=0;i<m-1;i++)
        {
            days=days+day[i];
        }
        System.out.println(days+d);
        sc.close();
    }
}
