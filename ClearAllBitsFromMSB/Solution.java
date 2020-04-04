public class Solution {

	public static int clearAllBits(int n, int i) {
		int m = 1;
		if(i<0)
			return n;
		if(i==0)
			m = 0;
		for (int j = 0; j < i-1; j++) {
			m = m<<1;
			m+=1;
		}
		return n&m;
	}

}