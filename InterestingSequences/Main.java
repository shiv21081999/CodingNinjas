import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int l = sc.nextInt();
		int[] arr = new int[n];
		int max = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
			if(arr[i] > max)
				max = arr[i];
			if(arr[i] < min)
				min = arr[i];
		}
		int ans_l = 0;
		for (int i = 0; i < arr.length; i++) {
			ans_l += ((max-arr[i])*l);
		}
		// System.out.println(ans_l);
		int ans_k = Integer.MAX_VALUE;
		int finaldec =-1, finalinc = -1;
		for (int i = min; i <= max; i++) {
			int inc = 0;
			int dec = 0;
			int cost = 0;
			for (int j = 0; j < arr.length; j++) {
				if(arr[j]-i>0)
					dec += (arr[j]-i);
				else if(arr[j]-i<0)
					inc += (i-arr[j]);

			}
			if(inc - dec >= 0)
			{
				cost = (dec*k)+((inc-dec)*l);
				if(cost < ans_k)
					ans_k = cost;
			}
		}
		int ans = (int)Math.min(ans_l,ans_k);
		System.out.println(ans);
	}
}