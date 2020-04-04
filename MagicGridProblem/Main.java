import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	static int[][] dp = new int[501][501];
	static int getTotalStrength(int[][] arr, int si, int sj, int ei, int ej)
	{
		if(si==ei && sj == ej)
		{
			int ans = 0;
			if(arr[si][sj] <= 0)
				ans = 0-arr[si][sj]+1;
			else
			{
				if(arr[si][sj] <=0)
					ans = 0-arr[si][sj]+1;
				else
					ans = 1;
			}
			dp[si][sj] = ans;
			// System.out.println(ans);
			return ans;
		}
		if(si>ei || sj>ej)
			return Integer.MAX_VALUE;
		if(dp[si][sj] != Integer.MIN_VALUE)
			return dp[si][sj];
		int option1 = getTotalStrength(arr, si+1, sj, ei, ej);
		int option2 = getTotalStrength(arr, si, sj+1, ei, ej);
		int ans = (int)Math.min(option1, option2);
		if(ans-arr[si][sj]<=0)
			ans = 1;
		else
			ans = ans - arr[si][sj];
		dp[si][sj] = ans;
		return ans;
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			int r = sc.nextInt();
			int c = sc.nextInt();
			int[][] arr = new int[r][c];
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					arr[i][j] = sc.nextInt();
				}
			}
			for (int i = 0; i < dp.length; i++) {
				Arrays.fill(dp[i],Integer.MIN_VALUE);
			}
			int ans = getTotalStrength(arr,0,0,r-1,c-1);
			System.out.println(ans);
			t--;
		}
		
	}
}