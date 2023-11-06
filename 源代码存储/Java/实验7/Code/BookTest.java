package 源代码存储.Java.实验7.Code;
import java.util.Date;
public class BookTest {  
    public static void main(String[] args) {  
        // 创建BookManagement对象  
        BookManagement bookManagement = new BookManagement();  
  
        // 添加书籍信息  
        bookManagement.addBook("9875631", "《Java程序设计》", "某老师", new Date());  
        bookManagement.addBook("9875632", "《C primer plus》", "author 2", new Date());  
        bookManagement.addBook("9875633", "Book3", "Author3", new Date());  
        bookManagement.addBook("9875634", "Book4", "Author4", new Date());  
        bookManagement.addBook("9875635", "Book5", "Author5", new Date());  
        bookManagement.addBook("9875636", "Book6", "Author6", new Date());  
        bookManagement.addBook("9875637", "Book7", "Author7", new Date());  
        bookManagement.addBook("9875638", "Book8", "Author8", new Date());  
  
        // 调用方法管理书籍信息  
        bookManagement.printBooksInfo(); // 打印所有书籍信息  
  
        // 根据ID排序  
        bookManagement.sortBooksByID();  
        System.out.println("After sorting by ID:");  
        bookManagement.printBooksInfo();  
  
        // 根据书名排序  
        bookManagement.searchBookByName();  
        System.out.println("After sorting by Name:");  
        bookManagement.printBooksInfo(); 
        System.out.println("调用查找算法"+(bookManagement.searchBookByName("《Java程序设计》"))); 
    }  
}