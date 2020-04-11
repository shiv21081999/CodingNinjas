
import java.util.*;
public class Solution {

	static int[][] dp = new int[0][0];
	public static int lcs(String s1, String s2){
		dp = new int[s1.length()+1][s2.length()+1];
		for (int i = 0 ; i < dp.length; i++) {
			Arrays.fill(dp[i],-1);
		}
		return longestCommonSubsequence(s1,s2);
	}
	public static int longestCommonSubsequence(String s1, String s2)
	{
		if(s1.length()==0 || s2.length() == 0)
			return 0;
		int ans = 0;
		if(dp[s1.length()][s2.length()] > -1)
			return dp[s1.length()][s2.length()];
		if(s1.charAt(0) == s2.charAt(0))
			ans = 1 + longestCommonSubsequence(s1.substring(1), s2.substring(1));
		else{
			ans = Math.max(longestCommonSubsequence(s1.substring(1), s2),longestCommonSubsequence(s1, s2.substring(1)));
		}
		dp[s1.length()][s2.length()] = ans;
		return ans; 
	}
	public static int lcs(String s1, String s2)
	{
		int m = s2.length();
		int n = s2.length();
		int[][] ans = new int[m+1][n+1];
		for (int i = 0; i < ans.length; i++) {
			ans[i][0] = 0;
		}
		for (int i = 0; i < ans[0].lenght; i++) {
			ans[0][i] = 0;
		}
		
	}
}
