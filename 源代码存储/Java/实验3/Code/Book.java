package 源代码存储.Java.实验3.Code;

public class Book {
    int bookID;
    String bookName;
    double price=0;
    String author;
    private static int nums=0;
    public Book()
    {
        //默认的构造函数
        {//bookID构造
            bookID=nums;
            nums++;
        }
        bookName ="未知";
        price=0.0;
        author="未知";
    }
    public Book(String bookName,double price,String author)
    {
        {//bookID构造
            bookID=nums;
            nums++;
        }
        this.bookName=bookName;
        this.price=price;
        this.author=author;
    }
    public Book(String bookName,String author)
    {
        {//ookID构造
            bookID=nums;
            nums++;
        }
        this.bookName=bookName;
        this.author=author;
    }
    public void set_bookName(String bookName)
    {
        this.bookName=bookName;
    }
    public void set_author(String author)
    {
        this.author=author;
    }
    public void set_price(double price)
    {
        this.price=price;
    }
    public double get_price()
    {
        return this.price;
    }
      public String get_author()
    {
        return this.author;
    }  
    public int  get_bookID()
    {
        return this.bookID;
    }
    public String get_bookName()
    {
        return this.bookName;
    }
    public String toString()
    {
        return " 本书编号"+bookID+" 名称"+bookName+" 价格"+price+" 作者"+author;
    }
}
