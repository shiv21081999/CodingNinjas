import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int n = sc.nextInt();
		int r = 1;
		while(n>0)
		{
			r*=x;
			n--;
		}
		System.out.println(r);
	}
}