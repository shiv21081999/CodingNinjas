import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	static long getAns(int[] arr, int start , int end)
	{
		if(start>= end)
			return 0;
		int mid = (start + end)/2;
		return getAns(arr, start, mid)+getAns(arr, mid+1, end)+merge(arr,start,mid,end);
	}
	static long merge(int[] arr, int start, int mid, int end){
		int i = start, j = mid+1,k=0;
		long sum = 0;
		int[] temp = new int[end - start + 1];
		while(i<=mid && j<=end)
		{
			if(arr[i] < arr[j])
			{
				sum += (arr[i]*(end-j+1));
				temp[k++] = arr[i++];
			}
			else
			{
				temp[k++] = arr[j++];
			}
		}
		while(i<=mid)
		{
			temp[k++] = arr[i++];
		}
		while(j<=end)
		{
			temp[k++] = arr[j++];
		}
		for ( k = 0,i=start; k < temp.length; k++,i++) {
			arr[i] = temp[k];
		}
		return sum;
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			int n = sc.nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < arr.length; i++) {
				arr[i] = sc.nextInt();
			}
			System.out.println(getAns(arr, 0, n-1));
			t--;
		}
		
	}
}