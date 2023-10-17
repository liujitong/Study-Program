package 源代码存储.Java.实验5.Code;

public class Circle implements IShape{
    double redius;//半径
    double posx;
    double posy;
    public Circle()
    {
        redius =1;
        posx=0;
        posx=1;
    }//无参构造函数，默认值101
    public Circle(double r,double x,double y)
    {
        redius =r;
        posx=x;
        posy=y;
    }
    public void setX(double x)
    {
        posx=x;
    }
    public void setY(double y)
    {
        posy=y;
    }    
    public void setR(double r)
    {
        redius=r;
    }
    public double getX(){
        return posx;
    }
    public double getY(){
        return posy;
    }
    public double getR(){
        return redius;
    }
    @Override
    public double getArea()
    {
        return Math.PI*redius*redius;
    }    //获取图形面积
    @Override
    public double getCircum()
    {
        return 2.0*Math.PI*redius;
    }  //获取图形周长
    @Override
    public void moveTo(int posx,int posy)
    {
        this.posx=posx;
        this.posy=posy;
        System.out.println("圆心被移动到了"+"("+posx+","+posy+")");
    }//移动图形到指定的位置
    @Override
    public void zoom(double i)
    {
    redius*=i;
    }    //对图形进行缩放，缩放比例i>0

}

