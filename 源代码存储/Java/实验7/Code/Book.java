package 源代码存储.Java.实验7.Code;

import java.util.Date;

public class Book{  
    private String bID;  
    private String bName;  
    private String author;  
    private Date publishDate;  
  
    // 无参构造方法  
    public Book() {  
    }  
  
    // 带参构造方法  
    public Book(String bID, String bName, String author, Date publishDate) {  
        this.bID = bID;  
        this.bName = bName;  
        this.author = author;  
        this.publishDate = publishDate;  
    }  
  
    // get和set方法  
    public String getbID() {  
        return bID;  
    }  
  
    public void setbID(String bID) {  
        this.bID = bID;  
    }  
  
    public String getbName() {  
        return bName;  
    }  
  
    public void setbName(String bName) {  
        this.bName = bName;  
    }  
  
    public String getAuthor() {  
        return author;  
    }  
  
    public void setAuthor(String author) {  
        this.author = author;  
    }  
  
    public Date getPublishDate() {  
        return publishDate;  
    }  
  
    public void setPublishDate(Date publishDate) {  
        this.publishDate = publishDate;  
    }  
    // toString方法，用于打印书籍信息  
    @Override  
    public String toString() {  
        return "Book [bID=" + bID + ", bName=" + bName + ", author=" + author + ", publishDate=" + publishDate + "]";  
    }

}