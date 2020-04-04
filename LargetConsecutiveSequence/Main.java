import java.util.Scanner;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		int n = s.nextInt();
		int arr[] = new int[n];

		for(int i = 0; i < n; i++) {
			arr[i] = s.nextInt();
		}

		ArrayList<Integer> ans = Solution.longestConsecutiveIncreasingSequence(arr);
		for(int num: ans) {
			System.out.println(num);
		}
	}
}