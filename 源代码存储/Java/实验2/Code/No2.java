package 源代码存储.Java.实验2.Code;
import java.util.Scanner;

public class No2 {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();//第一个矩阵的行数
		int m=sc.nextInt();
		//第一个矩阵的列数以及第二个矩阵的行数
		int k=sc.nextInt();//第二个矩阵的列数
		int Maze[][]=new int[n][m];
		int Maze1[][]=new int[m][k];
		int Maze2[][]=new int[n][k];
		for(int i=0;i<n;i++)//输入第一个矩阵的数据
		{
			for(int j=0;j<m;j++)
			{
				Maze[i][j]=sc.nextInt();
				
			}
		}
		for(int i=0;i<m;i++)//输入第二个矩阵的数据
		{
			for(int j=0;j<k;j++)
			{
				Maze1[i][j]=sc.nextInt();
				
			}   
		}
        Maze2 = matrix(Maze,Maze1);
        for(int i=0;i<n;i++)//将第三个矩阵输出出来
		{
			for(int j=0;j<k;j++)
			{
				System.out.print(Maze2[i][j]+" ");
				
			}
			System.out.println();
		}
        sc.close();
    }		
    public static int[][] matrix(int a[][], int b[][]) {
        //当a的列数与矩阵b的行数不相等时，不能进行点乘，返回null
        if (a[0].length != b.length)
            return null;
        //c矩阵的行数y，与列数x
        int y = a.length;
        int x = b[0].length;
        int c[][] = new int[y][x];
        for (int i = 0; i < y; i++)
            for (int j = 0; j < x; j++)
                //c矩阵的第i行第j列所对应的数值，等于a矩阵的第i行分别乘以b矩阵的第j列之和
                for (int k = 0; k < b.length; k++)
                    c[i][j] += a[i][k] * b[k][j];
        return c;
    }
}
