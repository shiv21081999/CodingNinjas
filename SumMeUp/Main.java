import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			long n = sc.nextLong();
			long sum = 0;
			while(n>0)
			{
				long r = n%10;
				sum += r;
				n/=10;
			}
			System.out.println(sum);
			t--;
		}
		
	}
}