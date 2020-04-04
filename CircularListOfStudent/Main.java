import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			int i = sc.nextInt();
			int p = sc.nextInt();
			System.out.println((i+p)%12);
			t--;
		}
		
	}
}