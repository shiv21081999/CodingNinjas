public class Solution {
	public static int turnOnIthBit(int n, int i) {
		if(i<0)
		{
			return n;
		}
		return n|(1<<i);
	}
}