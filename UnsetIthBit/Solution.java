public class Solution {
	public static int turnOffIthBit(int n, int i) {
		if(i<0)
			return n;
		return n &(~(1<<i));
	}
}