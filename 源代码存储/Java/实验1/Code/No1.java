package 源代码存储.Java.实验1.Code;
import java.util.Scanner;
public class No1 {

	public static void main(String[] args) 
	{
		String name;
		double day_gongzi;
		int days;
		double sorry;
		Scanner sc=new Scanner(System.in);
		System.out.println("姓名");
		name = sc.next();
		System.out.println("日工资");
		day_gongzi=sc.nextDouble();
		System.out.println("日");
		days = sc.nextInt();
		System.out.println("奖金");
		sorry = sc.nextDouble();
		System.out.print("员工");
		System.out.print(name);
		System.out.print("的工资为");
		System.out.print(sorry+days*day_gongzi);
		sc.close();
	}

}
 