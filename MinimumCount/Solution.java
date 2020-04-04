
public class Solution {
    static long[][] dp = new long[1001][500];
	
	public static long minCount(int n) {
		return minCount1(n,1);
	}
	public static long minCount1(int n ,int i){
		// System.out.println(n+" "+i*i);
		if(n==0)
			return 0;
		if(i*i > n)
			return Integer.MAX_VALUE;
			
		if(n<0)
			return Integer.MAX_VALUE;
        if(dp[n][i] > 0)
            return dp[n][i];
		long ans1 = minCount1(n-(i*i), i)+1;
		long ans2 = minCount1(n, i+1);
        dp[n][i] = (long)Math.min(ans1,ans2);
		return (long)Math.min(ans1,ans2);
	}
}