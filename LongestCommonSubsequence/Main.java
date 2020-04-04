import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
	
		String str1 = s.nextLine();
		String str2 = s.nextLine();
		System.out.println(Solution.lcs(str1, str2));
		
	}

}
