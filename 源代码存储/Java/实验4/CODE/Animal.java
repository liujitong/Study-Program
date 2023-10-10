package 源代码存储.Java.实验4.CODE;
abstract class Animal
{
    String type;
    String name;
    String color;
    //无参构造函数方法
    public Animal()
    {
        type="动物";
        name="xxx";
        color="x色";
    }
    //构造函数重载1;
    public Animal(String ty,String name)
    {
        type=ty;
        this.name=name;
    }
    //构造函数重载2
    public Animal(String ty,String name,String co)
    {
        type=ty;
        this.name=name;
        color=co;
    }
    //get函数
    String getType()
    {
        return type;
    }
    String getName()
    {
        return name;
    }
    String getColor()
    {
        return color;
    }
    //设置函数
    void setType(String ty)
    {
        type=ty;
    }
    void setName(String nm)
    {
        name=nm;
    }
    void setColor(String co)
    {
        color=co;
    }
    //抽象方法
    abstract void sleep();
    abstract void wakeUp();
    abstract void walk();
}
class Cat extends Animal
{
    int age;//设置年龄
    public Cat()
    {
        type="猫";
        name="xxx";
        color="x色";
        age=0;
    }
    //重载设置方法
    public Cat(String ty,String nm,String co,int age)
    {
        type=ty;
        name=nm;
        color=co;
        this.age=age;
    }
    void sleep()
    {
        System.out.println("The cat is sleeping!");
    }
    void wakeUp()
    {
        System.out.println("The cat wakes up!");
    }
    void walk()
    {
        System.out.println("The cat is walking silently.");
    }  
    public String toString()
    {
        return "这是一只"+age+"岁"+color+"色"+"叫做"+name+"的"+type;
    }
}
class Horse extends Animal
{
    int height;//设置年龄
    public Horse()
    {
        type="马";
        name="xxx";
        color="x色";
        height=0;
    }
    //重载设置方法
    public Horse(String ty,String nm,String co,int height)
    {
        type=ty;
        name=nm;
        color=co;
        this.height=height;
    }
    void sleep()
    {
        System.out.println("The horse is sleeping!");
    }
    void wakeUp()
    {
        System.out.println("The horse wakes up!");
    }
    void walk()
    {
        System.out.println("The horse is walking and shouting..");
    }  
    public String toString()
    {
        return "这是一只"+height+"高"+color+"色"+"叫做"+name+"的"+type;
    }
}
