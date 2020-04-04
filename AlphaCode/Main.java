import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	static long[] dp = new long[5005];
	static long mod = 1000000007;
	static long getCountOfCodes(String str, int n)
	{
		if(n<=1)
			return 1;
		if(dp[n]>0)
			return dp[n];
		long output = 0;
		if(str.charAt(n-1)!='0')
			output+= (getCountOfCodes(str, n-1)%mod);
		if(Integer.parseInt(str.substring(n-2,n))<=26 && str.charAt(n-2)!='0')
			output += (getCountOfCodes(str,n-2)%mod);
		dp[n] = output%mod;
		return output%mod;

	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		while(true)
		{
			String str = sc.next();
			if(str.equals("0"))
				break;
			Arrays.fill(dp, 0);
			long ans = getCountOfCodes(str,str.length());
			System.out.println(ans);
		}
	}
}