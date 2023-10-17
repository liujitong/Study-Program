package 源代码存储.Java.实验5.Code;

public class Triangle implements IShape{
    //设置三个点
    Point p1;
    Point p2;
    Point p3;
    double avx;//类中心点x
    double avy;//类中心点y
    public Triangle()
    {
        p1=new Point(0,0);
        p2=new Point(1,1);
        p3=new Point(2,2);
        avx=(0+1+2)*1.0/3;
        avy=avx;
    }
    public Triangle(double p1x,double p1y,double p2x,double p2y,double p3x,double p3y)
    {
        p1=new Point(p1x,p1y);
        p2=new Point(p2x,p2y);
        p3=new Point(p3x,p3y);
        avx=(p1x+p2x+p3x)/3;
        avy=(p1x+p2x+p3x)/3;
    }
    public void set_p1(double x,double y)
    {
        p1.setX(x);
        p1.setY(y);
        avx=(x+p2.x+p3.x)/3;
        avy=(y+p2.y+p3.y)/3;
    }
    public void set_p2(double x,double y)
    {
        p2.setX(x);
        p2.setY(y);
        avx=(p1.x+p2.x+p3.x)/3;
        avy=(p1.y+p2.y+p3.y)/3;
    }
    public void set_p3(double x,double y)
    {
        p3.setX(x);
        p3.setY(y);
        avx=(p1.x+p2.x+p3.x)/3;
        avy=(p1.y+p2.y+p3.y)/3;
    }
    //得到每个点的get函数
    public double get_p1_x(){ 
        return p1.getX();
    }
    public double get_p2_x(){ 
        return p2.getX();
    }
    public double get_p3_x(){ 
        return p3.getX();
    }
    public double get_p1_y(){ 
        return p1.getY();
    }
    public double get_p2_y(){ 
        return p2.getY();
    }
    public double get_p3_y(){ 
        return p3.getY();
    }
    
    @Override
    public double getArea()
    {
        double a=Instance(p1, p2);
        double b=Instance(p2, p3);
        double c=Instance(p3, p1);
        //海伦公式1/4*sqrt((a+b+c)(a+b-c)(a+c-b)(b+c-a))
        return 0.25*Math.sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a));
    }    //获取图形面积
    @Override
    public double getCircum()
    {
        return Instance(p1,p2)+Instance(p2, p3)+Instance(p1, p3);   
    }  //获取图形周长
    @Override
    public void moveTo(int posx,int posy)
    {
        avx=posx;
        avy=posy;
        System.out.println("三角形中心被移动到了"+"("+posx+","+posy+")");
    }//移动图形到指定的位置
    @Override
    public void zoom(double i)
    {
        //任意缩放，我选择p1 p2;
        p1.x=p1.x*i;
        p1.y=p1.y*i;
        p2.x=p2.x*i;
        p2.y=p2.y*i; 
    }    //对图形进行缩放，缩放比例i>0
    public double Instance(Point p1,Point p2)
    {
        return Math.sqrt(Math.pow((p1.x-p2.x),2)+Math.pow((p1.y-p2.y),2));
    }
}
