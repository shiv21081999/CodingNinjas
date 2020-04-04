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
		int swap = 0;
		for (int i = arr.length-1; i >= 0; i--) {
			if(arr[i] != i+1)
			{
				if(i-1>=0)
				{
					if(arr[i-1] == i+1)
					{
						swap++;
						int temp = arr[i-1];
						arr[i-1] = arr[i];
						arr[i] = temp;
					}
					else if(i-2>=0)
					{
						if(arr[i-2] == i+1)
						{
							swap += 2;
							arr[i-2] = arr[i-1];
							arr[i-1] = arr[i];
							arr[i] = i+1;
						}
					}
				}
				
			}
		}
		boolean flag = true;
		for (int i = 0; i < arr.length; i++) {
			if(arr[i] != i+1)
			{
				flag = false;
			}
		}
		if(flag)
		{
			System.out.println("YES");
			System.out.println(swap);
		}
		else
			System.out.println("NO");
	}
}