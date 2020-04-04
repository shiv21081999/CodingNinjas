import java.util.*; 
public class solution {
	public int solve(int n,int arr[])
	{
		int[] freq = new int[1001];
		for (int i = 0; i < arr.length; i++) {
			freq[arr[i]]++;
		}
		Integer[] ans = new Integer[1001];
		ans[0] = 0;
		ans[1] = freq[1];
		for (int i = 2; i < ans.length; i++) {
			int x = freq[i] * i;
			ans[i] = (int) Math.max(x+ans[i-2],ans[i-1]);
		}
		return Collections.max(Arrays.asList(ans));
	}
}