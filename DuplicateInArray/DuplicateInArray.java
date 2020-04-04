public class DuplicateInArray{	

	public static long duplicate(int[] arr){  
		long sum = (arr.length-2)*(arr.length-1);
		sum/=2;
		long arrsum = 0;
		for (int i = 0; i < arr.length; i++) {
			arrsum+=arr[i];
		}
		return arrsum - sum;
	}
}