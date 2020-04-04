import java.util.*;
public class Solution {

	public static String removeConsecutiveDuplicates(String s) {
		if(s.length()==1)
		{
			return s;
		}
		String ans = removeConsecutiveDuplicates(s.substring(1));
		if(s.charAt(0)==s.charAt(1))
			return ans;
		return s.charAt(0)+ans;
	}

}