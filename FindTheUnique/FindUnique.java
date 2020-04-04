public class FindUnique{	

	public static int findUnique(int[] arr){
		int a = 0;
		for (int i = 0; i < arr.length; i++) {
			a = a^arr[i];
		}
		return a ;
	}
}