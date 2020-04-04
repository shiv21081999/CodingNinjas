import java.util.*;
import java.util.Arrays;
import java.util.Collections;
import java.math.BigInteger;
public class Main {
	static int[][] dp = new int[0][0];
	static boolean isSumPresent(int[] arr, int sum, int i)
	{
		if(sum == 0)
			return true;
		if(i == arr.length)
			return false;
		if(sum < 0)
			return false;
		if(dp[i][sum] !=-1)
		{
			if(dp[i][sum] == 0)
				return false;
			else
				return true;
		}
		boolean flag1 = isSumPresent(arr,sum - arr[i] , i+1);
		boolean flag2 = isSumPresent(arr,sum,i+1);
		if(flag1||flag2)
			dp[i][sum] = 1;
		else
			dp[i][sum] = 0;
		return flag1||flag2;
	}
    public static void main(String args[]) {
    	Scanner sc = new Scanner(System.in);
    	int n  = sc.nextInt();
    	int[] arr = new int[n] ;
    	for (int i = 0 ; i < arr.length ; i++) {
    		arr[i] = sc.nextInt();
    	}
    	int sum = sc.nextInt();
    	dp = new int[n+1][sum+1];
    	for (int i = 0 ; i < dp.length ; i++) {
    		Arrays.fill(dp[i],-1);
    	}
    	if(isSumPresent(arr,sum , 0))
    		System.out.println("Yes");
    	else
    		System.out.println("No");
    }
}