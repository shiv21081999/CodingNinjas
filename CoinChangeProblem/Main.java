import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int numDenominations = s.nextInt();
		int denominations[] = new int[numDenominations];
		for(int i = 0; i < numDenominations; i++){
			denominations[i] = s.nextInt();
		}
		
		int value = s.nextInt();
		
		System.out.println(Solution.countWaysToMakeChange(denominations, value));
		
	}

}
