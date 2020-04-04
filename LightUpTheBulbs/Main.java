import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		String binary = sc.next();
		long count = 0;
		if(binary.charAt(0)=='0')
			count = 1;
		
		for (int i = 0; i < binary.length()-1; i++) {
			if(binary.charAt(i) == '1' && binary.charAt(i+1) == '0')
				count++;
		}
		long min = (long)Math.min(x,y);
		long ans = ((count-1)*min)+y;
		if(count==0)
			ans =0;
		System.out.println(ans);
	}
}