import java.util.Scanner;

public class No3 {
    public static void main(String[] args) {
        int [][][]a=new int[3][20][3];
        int []class2=new int[3];
        //编号0为C语言，编号1为数据结构，编号2为Java
        int n;
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<3;i++)
        {
        System.out.println("第"+(i+1)+"个班有几个人");
        n=sc.nextInt();
        class2[i]=n;
        for(int j=0;j<n;j++){
            System.out.println("第"+(i+1)+"班的第"+(j+1)+"人的C成绩");
            a[i][j][0]=sc.nextInt();
            System.out.println("第"+(i+1)+"班的第"+(j+1)+"人的数据结构成绩");
            a[i][j][1]=sc.nextInt();
            System.out.println("第"+(i+1)+"班的第"+(j+1)+"人的JAVA成绩");
            a[i][j][2]=sc.nextInt();
        }
        }
        int max1=0;
        int min1=100;
        int max2=0;
        int min2=100;
        int max3=0;
        int min3=100;
        int sum1=0;
        int sum2=0;
        int sum3=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<class2[i];j++)
            {
                    if(a[i][j][0]>max1) max1=a[i][j][0];
                    if(a[i][j][0]<min1) min1=a[i][j][0];
                    sum1+=a[i][j][0];
                    if(a[i][j][1]>max2) max2=a[i][j][1];
                    if(a[i][j][1]<min2) min2=a[i][j][1];
                    sum2+=a[i][j][1];
                    if(a[i][j][2]>max3) max3=a[i][j][2];
                    if(a[i][j][2]<min3) min3=a[i][j][2];
                    sum3+=a[i][j][2];                    
            }
        }
            System.out.println((double)sum1/(class2[0]+class2[1]+class2[2])*1.0);
            System.out.println((double)sum2/(class2[0]+class2[1]+class2[2])*1.0);
            System.out.println((double)sum3/(class2[0]+class2[1]+class2[2])*1.0);
            System.out.println("MAX");
            System.out.println(max1);
            System.out.println(max2);
            System.out.println(max3);
            System.out.println("MIN");
            System.out.println(min1);
            System.out.println(min2);
            System.out.println(min3);
        sc.close();
        }
}
