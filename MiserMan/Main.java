import java.util.*;
import java.util.Arrays;
import java.util.Collections;
import java.math.BigInteger;
public class Main {
	static int getAns(int[][] arr, int n , int m)
	{
		int[][] ans =  new int[n][m];
		for (int i = 0 ; i < m; i++) {
			ans[0][i] = arr[0][i];
		}
		for (int i = 1 ; i < n ; i++) {
			for (int j = 0 ; j < m ; j++) {
				if(j == 0)
				{
					ans[i][j] = (int) Math.min(ans[i-1][j],ans[i-1][j+1])+arr[i][j];
				}
				else if(j == m - 1)
				{
					ans[i][j] = (int)Math.min(ans[i-1][j],ans[i-1][j-1])+arr[i][j];
				}
				else
				{
					ans[i][j] = (int)Math.min(ans[i-1][j] , Math.min(ans[i-1][j-1],ans[i-1][j+1]))+arr[i][j];
				}
			}
		}
		int finalans = Integer.MAX_VALUE;
		for (int i = 0 ; i < m ; i++) {
			if(ans[n-1][i]<finalans)
				finalans = ans[n-1][i];
		}
		return finalans;
	}
    public static void main(String args[]) {
    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
    	int m = sc.nextInt();
    	int[][] arr = new int[n][m];
    	for (int i = 0 ; i < arr.length ; i++) {
    		for (int j = 0 ; j < arr[0].length; j++) {
    			arr[i][j] = sc.nextInt();
    		}
    	}
    	int ans = getAns(arr, n, m);
    	System.out.println(ans);
    }
}