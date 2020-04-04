
public class Solution {
	public static int getMaxMoney(int arr[], int n){
		int[] ans = new int[n];
		ans[0] = arr[0];
		ans[1] = (int)Math.max(arr[0],arr[1]);
		for (int i = 2; i < ans.length; i++) {
			ans[i] = (int) Math.max(ans[i-1],ans[i-2]+arr[i]);
		}
		return ans[n-1];
	}
}
