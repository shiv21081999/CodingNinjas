import java.util.Scanner;
import java.util.*;
public class Main {

	static long[][][] dp = new long[123][123][123];
	static String a = "";
	static String b = "";
	static long getHappiness(int n , int m, int k)
	{
		if(k==0)
			return 0;
		if(n == a.length() || m == b.length())
		{
			return Long.MIN_VALUE;
		}
		if(dp[n][m][k]!=-1)
			return dp[n][m][k];
		long ans = -1;
		if(a.charAt(n) == b.charAt(m))
		{
			if(k>0)
			{
				ans = (long)Math.max(getHappiness(n+1,m+1,k-1)+a.charAt(n),Math.max(getHappiness(n+1,m,k),getHappiness(n,m+1,k)));
				dp[n][m][k] = ans;
				return ans;
			}
			else 
				return 0;
		}
		long ans1 = getHappiness(n+1, m, k);
		long ans2 = getHappiness(n,m+1, k);
		dp[n][m][k] = (long)Math.max(ans1,ans2);
		return (long)Math.max(ans1,ans2);

	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			a = sc.next();
			b = sc.next();
			int k = sc.nextInt();
			// System.out.println(a+" "+b);
			for (int i = 0 ;  i < dp.length ; i++ ) {
				for (int j = 0 ; j < dp[0].length; j++) {
					Arrays.fill(dp[i][j],-1);
				}
			}
			long ans = getHappiness(0,0,k);
			System.out.println((long)Math.max(ans,0));
			t--;
		}
	}

}