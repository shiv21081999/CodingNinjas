public class solution {

	
	public static String dictionary(int n)
	{
		String[] arr = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		return arr[n];
	}
	public static String[] keypad(int n){
		if(n==0 || n==1)
		{
			String[] temp = new String[1];
			temp[0] = "";
			return temp;
		}
		String[] ans = keypad(n/10);
		String str = dictionary(n%10);
		String[] newans = new String[str.length()*ans.length];
		int k=0;
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < ans.length; j++) {
				newans[k++] = ans[j]+str.charAt(i);
			}
		}
		return newans;
	}
	
}
