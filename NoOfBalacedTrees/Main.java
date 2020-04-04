import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int height = s.nextInt();
		System.out.println(Solution.balancedTreesOfHeightH(height));
	}
}