public class ArrayRotate {	

	public static void rotate(int[] arr, int d) {
		d = d%arr.length;
		int[] temp = new int[d];
		for (int i = 0; i < d; i++) {
			temp[i] = arr[i] ;
		}
		for (int i = 0; i < arr.length-d; i++) {
			arr[i] = arr[i+d];
		}
		for (int i = arr.length - d; i < arr.length; i++) {
			arr[i] = temp[i-(arr.length - d)];
		}
	}
}