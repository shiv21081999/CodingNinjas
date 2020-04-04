public class Solution {
	public static int turnOffFirstSetBit(int n) {
		int m = 1;
		while(true)
		{
			if((n&m)>=1)
				break;
			m = m<<1;
		}
		
		return n&(~m);
	}
}