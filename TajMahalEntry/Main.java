import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
		}
		int[] t = new int[n];
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < arr.length; i++) {
			int x = (arr[i]-i)/n;
			if(arr[i] - i < 0)
				t[i] = 0;
			else if(x*n==arr[i]-i)
				t[i] = x;
			else
				t[i] = x+1;
			if(t[i] < min)
				min = t[i];
		}
		// System.out.println(Arrays.toString(t));
		for (int i = 0; i < t.length; i++) {
			if(t[i]==min)
			{
				System.out.println(i+1);
				break;
			}
		}
	}
}