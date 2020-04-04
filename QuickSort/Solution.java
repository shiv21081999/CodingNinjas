import java.util.*;
public class Solution {
	static void shuffle(int[] arr, int n)
	{
		Random rand = new Random();
		for (int i = n-1; i >= 0; i--) {
			int index = rand.nextInt(n);
			int temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;
		}
	}
	public static void quickSort(int[] input) {
		int[] arr = new int[input.length+1];
		shuffle(input,input.length);
		for(int i = 0 ; i < input.length ; i++)
		{
			arr[i] = input[i];
		}
		arr[arr.length-1] = Integer.MAX_VALUE;
		quickSort(arr,0,arr.length-1);
		for (int i = 0; i < input.length; i++) {
			input[i] = arr[i];
		}
	}
	static int partition(int[] arr, int start, int end)
	{
		int i = start , j= end, pivot = arr[start];
		while(i<=j)
		{
			do{
				j--;
			}while(arr[j]>pivot);
			do{
				i++;
			}
			while(arr[i]<=pivot);
			if(i<j)
			{
				int temp = arr[i] ;
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		arr[start] = arr[j] ;
		arr[j] = pivot;
		return j;
	}
	public static void quickSort(int[] arr,int start, int end)
	{
		if(start>=end)
		{
			return;
		}
		int pivot = partition(arr, start, end);
		quickSort(arr,start, pivot);
		quickSort(arr,pivot+1,end);
		
	}
	
}