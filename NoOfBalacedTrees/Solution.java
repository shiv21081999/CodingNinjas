public class Solution {
	static int mod = 1000000007;

	public static int balancedTreesOfHeightH(int h){
		if(h==0)
			return 0;
		if(h==1)
			return 1;
		if(h==2)
			return 3;
		int x = balancedTreesOfHeightH(h-1);
		int y = balancedTreesOfHeightH(h-2);
		return ((((x%mod)*(x%mod))%mod)+(((2%mod)*(x%mod)*(y%mod))%mod))%mod;
		
	}
}