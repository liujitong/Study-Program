package 源代码存储.Java.实验5.Code;

public class Point implements IShape{
    double  x,y;
    public Point(){//无参
        x=0;
        y=0;
    }
    public Point(double x,double y){
        this.x=x;
        this.y=y;
    }
    public void setX(double x){
        this.x=x;
    }
    public void setY(double y){
        this.y=y;
    }
    public double getX(){
        return x;
    }
    public double getY(){
        return y;
    }
    @Override
    public double getArea()
    {
        return 0;
    }    //获取图形面积
    @Override
    public double getCircum()
    {
        return 0;
    }  //获取图形周长
    @Override
    public void moveTo(int posx,int posy)
    {
        x=posx;
        y=posy;
    }//移动图形到指定的位置
    @Override
    public void zoom(double i)
    {
               
    }    //对图形进行缩放，缩放比例i>0
}
