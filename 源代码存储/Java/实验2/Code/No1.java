package 源代码存储.Java.实验2.Code;
public class No1
{
    public static void main(String[] args) {
        double x1,x2,x3;
        x1=(double)(Math.random()*2*Math.PI);
        x2=(double)(Math.random()*2*Math.PI);
        x3=(double)(Math.random()*2*Math.PI);
       Point p1= new Point(x1);
       Point p2= new Point(x2);
       Point p3= new Point(x3);
       System.out.println("输出");
       System.out.println(length(p1.x,p1.y,p2.x,p2.y));
       System.out.println(length(p3.x,p3.y,p2.x,p2.y));
       System.out.println(length(p1.x,p1.y,p3.x,p3.y));
       System.out.println(zhouchang(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y));
       System.out.println(mianji(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y));
    }
    public static double length(double x,double y,double x2,double y2)
    {
        return Math.sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
    }
    public static double zhouchang(double x,double y,double x2,double y2,double x3,double y3)
    {
        return length(x, y, x2, y2)+length(x3, y3, x2, y2)+length(x,y,x3,y3);
    }
    public static double mianji(double x,double y,double x2,double y2,double x3,double y3)
    {
        double a=length(x, y, x2, y2);
        double b=length(x3, y3, x2, y2);
        double c=length(x,y,x3,y3);
        double p=(a+b+c)/2;
        return Math.sqrt(p*(p-a)*(p-b)*(p-c));
    }
}