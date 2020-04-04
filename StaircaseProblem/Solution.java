
public class Solution {
	
	static long[] dp = new long[80];
		
	public static long staircase(int n){
			if(n==1)
				return 1;
			if(n==2)
				return 2;
			if(n==3)
				return 4;
			if(dp[n]>0)
				return dp[n];
			long ans = staircase(n-1)+staircase(n-2)+staircase(n-3);
			dp[n] = ans;
			return ans;
		}
		
	}
	