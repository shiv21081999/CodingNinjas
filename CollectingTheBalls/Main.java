import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	static boolean isPossible(long n, long mid)
	{
		long mr_sharma = 0,mr_singh = 0;
		long r = n;
		while(n>0)
		{
			if(n<mid)
			{
				mr_sharma+=n;
				n = 0;
				break;
			}
			mr_sharma +=mid;
			n -= mid;
			mr_singh += (n/10);
			n -= (n/10);
		}
		if(r%2!=0)
			r++;
		if(mr_sharma>= r/2)
			return true;
		return false;
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		long ans = -1;
		long n = sc.nextLong();
		long start = 1, end = n;
		while(start <= end)
		{
			long mid = (start + end)/2;
			if(isPossible(n,mid))
			{
				ans = mid;
				end = mid-1;
			}
			else
				start = mid+1;
		}
		System.out.println(ans);
	}
}