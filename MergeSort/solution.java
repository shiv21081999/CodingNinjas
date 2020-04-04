public class solution {

	public static void mergeSort(int[] input){
		mergeSort(input,0,input.length-1);
	}
	public static void mergeSort(int[] arr, int start ,int end)
	{
		if(start>=end)
			return;
		int mid = (start + end)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
	public static void merge(int[] arr,int start ,int mid ,int end)
	{
		int i = start, j = mid+1, k = 0;
		int[] temp = new int[end-start+1];
		while(i<=mid && j<=end)
		{
			if(arr[i] < arr[j]){
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
		for(i = start, k = 0; k<temp.length ; k++, i++)
		{
			arr[i] = temp[k];
		}
	}

}
