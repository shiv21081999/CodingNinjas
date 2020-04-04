
public class Solution {

	public static int getMin(int arr[], int n){
		int[] ans = new int[n];
		for (int i = 0; i < ans.length; i++) {
			ans[i] = 1;
		}
		for (int i = 1; i < ans.length; i++) {
			if(arr[i] > arr[i-1])
				ans[i] = ans[i-1] + 1;
		}
		for (int i = n-1; i > 0; i--) {
			if(arr[i-1] > arr[i] && ans[i-1] <= ans[i])
				ans[i-1] = ans[i] + 1;
		}
		int sum = 0;
		for (int i = 0; i < ans.length; i++) {
			sum += ans[i];
		}
		return sum;
  }
}
