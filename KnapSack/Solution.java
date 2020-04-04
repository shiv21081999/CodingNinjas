import java.util.*;
public class Solution {
	
	static int[][] ans = new int[0][0];
	public static int knapsack(int[] weight,int value[],int maxWeight){
		int[][] ans = new int[2][maxWeight+1];
		int finalans = Integer.MIN_VALUE;
		for (int i = 0 ; i < weight.length ;i++ ) {
			for (int j = 1; j <=maxWeight ; j++) {
				if(weight[i] <= j)
					ans[1][j] = (int)Math.max(ans[0][j],ans[0][j-weight[i]]+value[i]);
				if(ans[1][j] > finalans)
					finalans = ans[1][j];
			}
			for (int j = 1; j <=maxWeight ; j++) {
				ans[0][j] = ans[1][j];
			}
		}
		return finalans;
	}
	public static int knapsack(int[] weight , int[] value , int maxWeight, int i)
	{
		if(i == weight.length)
			return 0;
		if(maxWeight == 0)
			return 0;
		if(ans[i][maxWeight] >0)
			return ans[i][maxWeight];
		int ans2 = -1;
		if(weight[i] <= maxWeight)
			ans2 = knapsack(weight ,value, maxWeight-weight[i],i+1);
		int ans1 = knapsack(weight,value,maxWeight,i+1);
		if(ans2>=0)
			ans2+=value[i];
		ans[i][maxWeight] = (int)Math.max(ans2,ans1);
		return ans[i][maxWeight];
	}
	
}
