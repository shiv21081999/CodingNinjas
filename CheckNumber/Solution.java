public class Solution {
	
	public static boolean checkNumber(int input[], int x) {
		return checkNumberInArray(input,x,0);
	}
	public static boolean checkNumberInArray(int[] input, int x, int index)
	{
		if(index == input.length)
			return false;
		if(input[index] == x)
			return true;
		return checkNumberInArray(input, x, index+1);
	}
}