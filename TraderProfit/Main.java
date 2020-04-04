import java.util.*;
import java.util.Arrays;
import java.util.Collections;
import java.math.BigInteger;
public class Main {
	static int[][][] dp = new int[31][31][11];
	static int getMaxProfit(int[] arr ,int i , int j ,int k)
	{
		if(k == 0)
			return 0;
		if(i >= j )
			return 0;
		if(j >= arr.length)
			return 0;
		if(i >= arr.length)
			return 0;
		if(dp[i][j][k] != -1)
			return dp[i][j][k];
		int ans1 = -1;
		if(arr[j] - arr[i] >= 0)
			ans1 = getMaxProfit(arr , j+1, j+2 , k-1);
		if(ans1 >= 0)
			ans1 += (arr[j] - arr[i]);

		int ans2 = getMaxProfit(arr, i , j+1, k);
		int ans3 = getMaxProfit(arr, i+1 , j , k);
		dp[i][j][k] = (int)Math.max(Math.max(ans1,ans2),ans3);
		return (int)Math.max(Math.max(ans1,ans2),ans3);
	}
    public static void main(String args[]) {
    	Scanner sc = new Scanner(System.in);
    	int t = sc.nextInt();
    	while(t>0)
    	{
    		int k = sc.nextInt();
    		int n = sc.nextInt();
    		int[] arr = new int[n];
    		for (int i = 0 ; i < n; i++) {
    			arr[i] = sc.nextInt();
    		}
    		for (int i = 0 ;  i < 31 ; i++) {
    			for (int j = 0 ; j < 31 ; j++) {
    				Arrays.fill(dp[i][j] , -1);
    			}
    		}
    		int ans = getMaxProfit(arr, 0, 1 ,k);
    		System.out.println(ans);
    		t--;
    	}
    }
}