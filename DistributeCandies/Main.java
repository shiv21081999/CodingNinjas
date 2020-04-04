import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	static boolean isPossible(int[] arr, int mid, int k)
	{
		int dis = 0;
		for (int i = 0; i < arr.length; i++) {
			dis+= (arr[i]/mid);
			if(dis>=k)
			{
				return true;
			}
		}
		return false;
	}
	static int getMaxDistributed(int[] arr,int min , int max, int k)
	{
		int i = min,j = max;
		int ans = 0;
		while(i<=j)
		{
			int mid = (i+j)/2;
			if(isPossible(arr,mid,k))
			{
				ans = mid;
				i = mid+1;
			}
			else 
			{
				j = mid -1;
			}
		}
		return ans;
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			int n = sc.nextInt();
			int k = sc.nextInt();
			int max = Integer.MIN_VALUE;
			int[] arr = new int[n];
			for (int i = 0; i < arr.length; i++) {
				arr[i] = sc.nextInt();
				if(arr[i] > max)
					max = arr[i];
			}
			System.out.println(getMaxDistributed(arr, 0,max,k));
			t--;
		}
		
	}
}