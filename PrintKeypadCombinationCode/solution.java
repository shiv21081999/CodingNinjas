public class solution {
	public static String dictionary(int n)
	{
		String[] arr = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		return arr[n];
	}

	public static void printKeypad(int input){
		printKeypad(input,"");
	}
	public static void printKeypad(int n , String ans)
	{
		if(n == 0)
		{
			System.out.println(ans);
			return;
		}
		String str = dictionary(n%10);
		for (int i = 0; i < str.length(); i++) {
			printKeypad(n/10, str.charAt(i)+ans);
		}
	}
}
