
public class solution {
	
	long solve(int[] A,int n){
		
		return countInversions(A,0,n-1);
		
	}
	long countInversions(int[] arr, int start , int end)
	{
		if(start>=end)
			return 0;
		int mid = (start + end)/2;
		return countInversions(arr,start,mid)+countInversions(arr,mid+1,end)+merge(arr,start,mid,end);
	}
	long merge(int[] arr, int start, int mid , int end){
		int i = start , j = mid +1,k=0;
		long count = 0;
		int[] temp = new int[end-start+1];
		while(i<=mid && j<=end)
		{
			if(arr[i]>arr[j])
			{
				count+=(mid-i+1);
				temp[k++] = arr[j++];
			}
			else
			{
				temp[k++] = arr[i++];
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
		for(k=0,i=start;k<temp.length;i++,k++)
		{
			arr[i] = temp[k];
		}
		return count;
	}
	
}
