import java.util.*;
public class Solution {
	
	static long[] getIncreasingSubSequence(int[] arr, int n)
	{
		long[] ans = new long[n];
		ans[0] = 1;
		for (int i = 1; i < ans.length; i++) {
			ans[i] = 1;
			for (int j = i-1; j >= 0; j--) {
				if(arr[j] >= arr[i])
					continue;
				long possibleOut = 1+ans[j];
				if(possibleOut>ans[i])
					ans[i] = possibleOut;
			}
		}
		return ans;
	}
	static long[] getDecreasingSubSequence(int[] arr, int n)
	{
		long[] ans = new long[n];
		ans[n-1] = 1;
		for (int i = n-2; i >=0; i--) {
			ans[i] = 1;
			for (int j = i+1; j < n; j++) {
				if(arr[j] >= arr[i])
					continue;
				long possibleOut = ans[j]+1;
				if(possibleOut > ans[i])
					ans[i] = possibleOut;
			}
		}
		return ans;
	}
	
	public static long longestBitonicSubarray(int[] arr){

		long ans = 0;
        int n = arr.length;
		long[] inc = getIncreasingSubSequence(arr,n);
		long[] dec = getDecreasingSubSequence(arr,n);
		for (int i = 0; i < dec.length-1; i++) {
			if(inc[i]+dec[i]-1 > ans)
				ans = inc[i] + dec[i] - 1;
		}
		// System.out.println(Arrays.toString(inc));
		// System.out.println(Arrays.toString(dec));
        return ans;
		
	}
	
}
