import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
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
			for (int i = 0; i < arr.length-1; i++) {
				if(arr[i] > arr[i+1])
				{
					int temp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = temp;
				}
			}
			boolean flag = true;
			for (int i = 0; i < arr.length; i++) {
				if(arr[i]!=i)
					flag = false;
			}
			if(flag)
				System.out.println("Yes");
			else
				System.out.println("No");
			t--;
		}
		
	}
}