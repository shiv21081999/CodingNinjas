import java.util.*;
class TrueFalse{
	boolean visited = false;
	int index = 0;
}
public class Solution {
	public static ArrayList<Integer> longestConsecutiveIncreasingSequence(int[] arr) {
		HashMap<Integer,TrueFalse> map = new HashMap<>();
		for (int i = 0; i < arr.length; i++) {
			if(!map.containsKey(arr[i]))
			{
				TrueFalse temp = new TrueFalse();
				temp.index = i;
				map.put(arr[i], temp);
			}
		}
		int finalStart = arr[0],finalEnd = arr[0];
		for (int i = 0; i < arr.length; i++) {
			if(!map.get(arr[i]).visited)
			{
				boolean flag = true;
				int start = arr[i];
				int end = arr[i];
				while(flag)
				{
					if(map.containsKey(start-1))
					{
						TrueFalse temp = map.get(start-1);
						temp.visited = true;
						map.put(start-1, temp);
						start--;
					}
					else{
						flag = false;
					}
				}
				flag = true;
				while(flag)
				{
					if(map.containsKey(end+1))
					{
						TrueFalse temp = map.get(end+1);
						temp.visited = true;
						map.put(end+1, temp);
						end++;
					}
					else
					{
						flag = false;
					}
				}
				if(end-start>finalEnd-finalStart)
				{
					finalStart = start;
					finalEnd = end;
				}
				else if(end-start==finalEnd-finalStart)
				{
					if(map.get(start).index<map.get(finalStart).index)
					{
						finalStart = start;
						finalEnd = end;
					}

				}
			}
		}
		ArrayList<Integer> ans = new ArrayList<>();
		for (int i = finalStart; i <= finalEnd; i++) {
			ans.add(i);
		}
		return ans;
	}
}