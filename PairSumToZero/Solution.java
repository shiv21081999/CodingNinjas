import java.util.*;

public class Solution {
	public static void PairSum(int[] input, int size) {
		HashMap<Integer,Integer> map = new HashMap<>();
		for (int i = 0; i < input.length; i++) {
			if(input[i] < 0)
			{
				if(map.containsKey(input[i]))
				{
					int r = map.get(input[i]);
					map.put(input[i] , r+1);
				}
				else
					map.put(input[i], 1);
			}
		}
		for (int i = 0; i < input.length; i++) {
			if(input[i] >0)
			{
				if(map.containsKey(-1*input[i]))
				{
					int r = map.get(-1*input[i]);
					for (int j = 0; j < r; j++) {
						System.out.println(-1*input[i]+" "+input[i]);
					}
				}
			}
		}
	}
}