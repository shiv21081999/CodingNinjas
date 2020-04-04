
import java.util.*;
public class Solution {
	static int[][] dp = new int[0][0];

	public static int editDistance(String a , String b)
	{
		dp = new int[a.length()+1][b.length()+1];
		for (int i = 0 ; i < dp.length; i++) {
			Arrays.fill(dp[i],-1);
		}
		return editDistance1(a,b);
	}
	public static int editDistance1(String a , String b)
	{
		if(a.length() == 0)
			return b.length();
		if(b.length() == 0)
			return a.length();
		if(dp[a.length()][b.length()] > -1)
			return dp[a.length()][b.length()];
		int ans = 0;
		if(a.charAt(0)==b.charAt(0))
			ans = editDistance1(a.substring(1),b.substring(1));
		else
			ans = 1 + Math.min(Math.min(editDistance1(a.substring(1),b),editDistance1(a,b.substring(1))),editDistance1(a.substring(1),b.substring(1)));
		dp[a.length()][b.length()] = ans;
		return ans;	
	}
}
