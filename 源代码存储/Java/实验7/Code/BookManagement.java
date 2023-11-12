package 源代码存储.Java.实验7.Code;

import java.util.*;  
  
public class BookManagement {  
    private Map<String, Book> bookMap;  
  
    public BookManagement() {  
        bookMap = new HashMap<>();  
    }  
  
    // 添加书籍信息  
    public void addBook(String ID, String Name, String author, Date publishDate) {  
        Book book = new Book(ID,Name,author,publishDate);  
        bookMap.put(ID, book);  
    }  
  
    // 删除书籍信息  
    public void deleteBook(String ID) {  
        bookMap.remove(ID);  
    }  
  
    // 根据ID搜索书籍信息  
    public Book searchBookByID(String ID) {  
        return bookMap.get(ID);  
    }  
  
    // 根据书名搜索书籍信息  
    public List<Book> searchBookByName(String Name) {  
        List<Book> result = new ArrayList<>();  
        for (Book book : bookMap.values()) {  
            if (book.getbName().contains(Name)) {  
                result.add(book);  
            }  
        }  
        return result;  
    }  
  
    // 根据ID排序书籍信息  
    public void sortBooksByID() {  
        List<Book> bookList = new ArrayList<>(bookMap.values());  
        Collections.sort(bookList, Comparator.comparing(Book::getbID)); //调用排序算法 
        for (int i = 0; i < bookList.size(); i++) {  
            bookMap.put(bookList.get(i).getbID(), bookList.get(i));  
        }
        for(Book bk:bookList) System.out.println(bk);
    }  
  
    // 根据书名排序书籍信息  
    public void sortBookByName() {  
        List<Book> bookList = new ArrayList<>(bookMap.values());  
        Collections.sort(bookList, Comparator.comparing(Book::getbName));  
        for (int i = 0; i < bookList.size(); i++) {  
            bookMap.put(bookList.get(i).getbID(), bookList.get(i));  
        }  
        for(Book bk:bookList) System.out.println(bk);
    }  
  
    // 打印所有书籍信息  
    public void printBooksInfo() {  
        for (Book book : bookMap.values()) {  
            System.out.println(book);  
        }  
    }  
}