package 源代码存储.Java.实验3.Code;
import java.util.Scanner;
public class BookTest
{
    public static void main(String[] args) {
        Book []book=new Book[100];
        Scanner sc=new Scanner(System.in);
        String n,m;
        double t;
        int j=0;
        do
        {
            System.out.println("书名");
            n=sc.next();
            if(n=="1") break;
            System.out.println("价格");
            t=sc.nextDouble();  
            if(t==0) break;          
            System.out.println("作者");
            m=sc.next();
            book[j]=new Book(n,t,m);   
            j++;  
        }while (t!=0);
        for(int i=0;i<j;i++)
        {
            System.out.println(book[i]);
        }
        SortByprice(book,0,j-1);
        for(int i=0;i<j;i++)
        {
            System.out.println(book[i]);
        }
        System.out.println("查谁");
        searchByAuthor(book,sc.next(),j);
        sc.close();
    }
    public static void SortByprice(Book[] book,int s,int e)
    {
        if (s >= e) return;
        int i = s, j = e;
        double pivot = book[s].price;
        Book pivot1=book[s];
        while (i < j) {
            while (i < j && book[i].price <= pivot) {
                i++;
            }
            while (i < j && book[j].price >= pivot) {
                j--;
            }
            if (i < j) {
                Book temp = book[i];
                book[i] = book[j];
                book[j] = temp;
            }
        }
        book[s] = book[i];
        book[i] = pivot1;
        SortByprice(book, s, i - 1);
        SortByprice(book, i + 1, e);
    }
    public static void searchByAuthor(Book[] book,String author,int length)
    {
        int flag=0;
        for(int i=0;i<length;i++)
        {
            if(book[i].author.equals(author)) 
            {
                System.out.println(book[i]);
                flag=1;
            }
        }
        if(flag==0) System.out.println("无");
    }
}