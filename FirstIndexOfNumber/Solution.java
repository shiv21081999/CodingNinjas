
public class Solution {

	public static int firstIndex(int input[], int x) {
		return firstIndexOfOccurance(input,x,0);
	}
	public static int firstIndexOfOccurance(int[] input , int x, int index)
	{
		if(index==input.length)
			return -1;
		if(input[index] == x)
			return index;
		return firstIndexOfOccurance(input, x, index+1);
	}
	
}