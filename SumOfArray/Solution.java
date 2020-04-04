import java.util.Arrays;

public class Solution {

	public static int sum(int input[]) {
		if(input.length == 1 )
		{
			return input[0];
		}
		return input[0]+sum(Arrays.copyOfRange(input, 1 , input.length));
	}
}