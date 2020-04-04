import java.util.*;
public class TripletSum {	

	public static void FindTriplet(int[] arr, int x){
		Arrays.sort(arr, 0, arr.length);
		for (int i = 0; i < arr.length-1; i++) {
			for (int j = i+1; j < arr.length-1; j++) {
				for (int k = j+1; k < arr.length; k++) {
					if(arr[i] + arr[j] + arr[k] ==x)
					{
						System.out.println(arr[i] + " " + arr[j] + " " + arr[k]);
					}
				}
			}
		}
	}
}