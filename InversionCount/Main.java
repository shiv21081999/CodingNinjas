import java.util.*;

public class Main {
	
	static int MAXN = 100005;
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		int n;
		int[] A = new int[MAXN];
		n = scan.nextInt();
		for(int i = 0; i < n ; i++){
			A[i] = scan.nextInt();
		}
		System.out.println(new solution().solve(A,n));

	}

}
