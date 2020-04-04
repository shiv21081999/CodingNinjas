
public class Solution {

	public static int[] allIndexes(int input[], int x) {
		return allIndexes(input,x,0);
	}
	public static int[] allIndexes(int[] input , int x, int index)
	{
		if(index==input.length)
		{
			return new int[0];
		}
		int[] ans = allIndexes(input, x, index+1);
		if(input[index] == x)
		{
			int[] newans = new int[ans.length+1];
			newans[0] = index;
			for (int i = 0; i < ans.length; i++) {
				newans[i+1] = ans[i];
			}
			ans = newans;
		}
		return ans;
	}
	
}