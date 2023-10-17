package 源代码存储.Java.实验5.Code;
public interface IShape {
        double getArea();    //获取图形面积
        double getCircum();  //获取图形周长
        void moveTo(int posx,int posy);//移动图形到指定的位置
        void zoom(double i);    //对图形进行缩放，缩放比例i>0
}
