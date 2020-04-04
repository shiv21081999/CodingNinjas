import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class solution {
    public static String uniqueChar(String str){
        HashSet<Character> set = new HashSet<>();
        for (int i = 0; i < str.length(); i++) {
            set.add(str.charAt(i));
        }
        String ans = "";
        for (int i = 0; i < str.length(); i++) {
            if(set.contains(str.charAt(i)))
            {
                ans+=str.charAt(i);
                set.remove(str.charAt(i));
            }
        }
        return ans;
	}
}