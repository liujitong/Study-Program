public class No3 {
	public static void main(String[] args) {
	for(int i=0;i<9;i++)
		{
			for(int j=0;j<i+1;j++)
			{
				System.out.print(j+1);
				System.out.print("*");
				System.out.print(i+1);
				System.out.print("=");
				System.out.print((i+1)*(j+1));
				System.out.print(" ");
			}
			System.out.println();
		}
	}
}
