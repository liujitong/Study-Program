package 源代码存储.Java.实验5.Code;

public class Rectangle implements IShape{
    Point leftPoint;//左顶点
    double length;//长度
    double width;//宽度
    public Rectangle()
    {
        leftPoint=new Point(0,0);
        length=1;
        width=2;;
    }
    public Rectangle(int posx,int posy,int length,int width)
    {
        leftPoint=new Point (posx,posy);
        this.length=length;
        this.width=width;
    }
    @Override
    public double getArea()
    {
        return length*width;
    }    //获取图形面积
    @Override
    public double getCircum()
    {
        return (length+width)*2;   
    }  //获取图形周长
    @Override
    public void moveTo(int posx,int posy)
    {
        leftPoint.x=posx;
        leftPoint.y=posy;
        System.out.println("左顶点被移动到了"+"("+posx+","+posy+")");
    }//移动图形到指定的位置
    @Override
    public void zoom(double i)
    {
        length=length*i;
        width=width*i;
    }    //对图形进行缩放，缩放比例i>0
}
