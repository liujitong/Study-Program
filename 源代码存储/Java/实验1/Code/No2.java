import java.util.*;
public class No2{
	public static void main(String[] args){
		double a , b , c;
		double p , q , delta;
		double x1 , x2;
		Scanner scan = new Scanner (System.in);
		System.out.println("请输入一元二次方程的三个系数");
		a = scan.nextDouble();
		b = scan.nextDouble();
		c = scan.nextDouble();
		delta = b * b - 4 * a * c;
		p = -b / ( 2 * a ) ;
		q = Math.sqrt(Math.abs(delta)) / (2 * a);
		if(a== 0.0){
			System.out.println("二次方的系数为零，不是一个二次方程");
			
		}
		else if (delta > 0.0){
			x1 = p + q;
			x2 = p - q;
			System.out.println("方程有两个不等的实根");
			System.out.printf("x1=%.2f,x2=%.2f\n",x1,x2);
		}
		else if(delta == 0.0){
			x1 = x2 = p;
			System.out.println("方程有两个相等的实根");
			System.out.printf("x1 = x2 =%.2f\n",x1);
		}
		else{
			System.out.println("方程有两个复根");
			System.out.printf("x1=%.2f%+.2fi,",p,q);
			System.out.printf("x2=%.2f%+.2fi",p,-q);
		}
		scan.close();
	}	
}