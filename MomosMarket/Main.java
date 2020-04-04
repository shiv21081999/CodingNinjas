import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	static void printMaxMomo(int[] arr, int money)
	{
		int start = 0,end = arr.length-1;
		int ans = 0;
		boolean flag = false;
		while(start <= end)
		{
			int mid = (start+end)/2;
			if(arr[mid] <= money)
			{
				ans = mid;
				start = mid + 1;
				flag = true;
			}
			else
			{
				end = mid - 1;
			}
		}
		if(flag == true)
		{
			int money_left = money - arr[ans];
			System.out.println(ans+1+" "+money_left);
		} 
		else
		{
			System.out.println(ans+" "+money);
		}
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] preSum = new int[n];
		int sum = 0;
		for (int i = 0; i < preSum.length; i++) {
			int temp = sc.nextInt();
			sum += temp;
			preSum[i] = sum;
		}
		int q = sc.nextInt();
		while(q>0)
		{
			int money = sc.nextInt();
			printMaxMomo(preSum,money);
			q--;
		}
		
	}
}