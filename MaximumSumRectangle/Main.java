import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	static int getSum(int[][] arr ,int row ,int col){
		int sum = 0;
		for (int i = row; i < arr.length; i++) {
			for (int j = col; j < arr[0].length; j++) {
				sum += arr[i][j];
			}
		}
		return sum;
	}
	static int getMaxSumRec(int[][] arr, int n , int m)
	{
		int[][] ans = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int sum = getSum(arr,i,j);
				ans[i][j] = sum;
			}
		}
		int finalSum = Integer.MIN_VALUE;
		for (int si= 0; si< n; si++) {
			for (int sj = 0; sj < m; sj++) {
				for (int ei = si; ei < n; ei++) {
					for (int ej = sj; ej < m; ej++) {
						int sum = ans[si][sj];
						if(ei == n-1 && ej == m-1)
						{
							sum -= 0;
						}
						else if(ej == m-1)
						{
							sum -= (ans[ei+1][sj]);
						}
						else if(ei == n-1)
						{
							sum -= (ans[si][ej+1]);
						}
						else
						{
							sum -= (ans[si][ej+1] + ans[ei+1][sj] - ans[ei+1][ej+1]);
						}

						if(sum > finalSum)
							finalSum = sum;
					}
				}	
			}
		}
		return finalSum;
	}
	static int getMaxSumRecBetter(int[][] arr, int n , int m )
	{
		int sum[] = new int[n];
		int finalSum = Integer.MIN_VALUE;
		for (int l = 0; l < m; l++) {
			Arrays.fill(sum, 0);
			for (int r = l; r < m; r++) {
				for (int i = 0; i < n; i++) {
					sum[i] += arr[i][r];
				}
				int currSum = 0,best_so_far = Integer.MIN_VALUE;
				for (int i = 0; i < sum.length; i++) {
					currSum += sum[i];
					if(currSum > best_so_far)
						best_so_far = currSum;
					if(currSum < 0)
						currSum = 0;
				}
				if(best_so_far > finalSum)
					finalSum = best_so_far;
			}
		}
		return finalSum;
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		int ans = getMaxSumRecBetter(arr,n,m);
		System.out.println(ans);
	}
}