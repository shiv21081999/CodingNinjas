import java.util.*;
public class Solution {

	static int[][] dp = new int[1001][11];
;	public static int countWaysToMakeChange(int denominations[], int value){
		for (int i = 0; i < dp.length; i++) {
			Arrays.fill(dp[i],-1);
		}
		return countWaysToMakeChange(denominations , value , 0);
	}
	public static int countWaysToMakeChange(int[] arr, int value , int index)
	{
		if(value < 0)
			return 0;
		if(value == 0)
			return 1;
		if(index == arr.length)
			return 0;
		if(dp[value][index] > -1)
			return dp[value][index];
		int first = countWaysToMakeChange(arr, value-arr[index], index);
		int second = countWaysToMakeChange(arr, value, index+1);
		dp[value][index] = first + second;
		return first + second;
	}	
	
}