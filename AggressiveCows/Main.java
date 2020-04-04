import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	static boolean isPossible(int[] arr, int c ,int mid)
	{
		c--;
		int i =0,j=1;
		while(i<arr.length && j<arr.length)
		{
			if(arr[j]-arr[i]>=mid)
			{
				c--;
				i = j;
				if(c==0)
					return true;
			}
			j++;
		}
		if(c==0)
			return true;
		return false;
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			int n = sc.nextInt();
			int c = sc.nextInt();
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
			Arrays.sort(arr,0,n);
			int start = 1;
			int end = max - min;
			int  ans = 0;
			while(start <= end)
			{
				int mid = (start + end)/2;
				if(isPossible(arr,c,mid))
				{
					ans = mid;
					start = mid+1;
				}
				else{
					end = mid -1;
				}
			}
			System.out.println(ans);
			t--;
		}
		
	}
}