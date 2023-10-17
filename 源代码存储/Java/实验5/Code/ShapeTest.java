package 源代码存储.Java.实验5.Code;

import java.util.ArrayList;

public class ShapeTest {
public static void moveTo(IShape shape, int x, int  y) {  
    shape.moveTo(x, y);
}  

public static void printArea(IShape shape) {  
    System.out.println("Shape area: " + shape.getArea());  
}  

public static void printCircum(IShape shape) {  
    System.out.println("Shape circumference: " + shape.getCircum());  
}  
public static void zoom(IShape shape, double factor) {  
    shape.zoom(factor);   
}
    public static void main(String[] args) {
    ArrayList<IShape> shapes = new ArrayList<>();
    shapes.add(new Circle(5,0,0));  
    shapes.add(new Circle(10,0,0));  
    shapes.add(new Triangle(1,1,2,2,3,4));  
    shapes.add(new Triangle(0,3,4,0,0,0));  
    shapes.add(new Rectangle(0,0,2, 5));  
    shapes.add(new Rectangle(0,0,3,7));
    for(IShape i:shapes)
    {
        printCircum(i);
    }
    for(IShape i:shapes)
    {
        printArea(i);
    }
    //统一移动
    for(IShape i:shapes)
    {
        moveTo(i,0,2);
    }
    //统一缩放
    for(IShape i:shapes)
    {
        zoom(i, 10);
    }
    System.out.println("扩缩后");
    for(IShape i:shapes)
    {
        printCircum(i);
    }
    for(IShape i:shapes)
    {
        printArea(i);
    }
}   
  
}
