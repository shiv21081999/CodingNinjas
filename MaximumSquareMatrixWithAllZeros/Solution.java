import java.util.*;
public class Solution {
	
	public static int findMaxSquareWithAllZeros(int[][] arr){
		int n = arr.length, m = arr[0].length;
		int[][] ans = new int[n][m];
		for (int i = 0; i < n; i++) {
			if(arr[i][0] == 0)
				ans[i][0] = 1;
		}
		for (int i = 0; i < m; i++) {
			if(arr[0][i] == 0)
				ans[0][i] = 1;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if(arr[i][j] == 1)
					ans[i][j] = 0;
				else
					ans[i][j] = (int)Math.min(Math.min(ans[i-1][j-1],ans[i-1][j]),ans[i][j-1])+1;
			}
		}
		int finalans = 0;
		for (int i = 0; i < n; i++) {
			// System.out.println(Arrays.toString(ans[i]));
			for (int j = 0; j < m; j++) {
				if(ans[i][j] > finalans)
					finalans = ans[i][j];
			}
		}
		return finalans;
	}

	
}