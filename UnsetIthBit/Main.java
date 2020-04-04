import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		int n = s.nextInt();
		int i = s.nextInt();
		System.out.println(Solution.turnOffIthBit(n, i));
	}
}