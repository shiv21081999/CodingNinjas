import java.util.Scanner;

public class Main {
	public static int[] A=new int [100005];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n;
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		for(int i=0;i<n;i++)
		{
			A[i]=scan.nextInt();
		}
		System.out.println(new solution().solve(n,A));
	}

}
