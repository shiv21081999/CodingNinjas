import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String str = sc.next();
        int a = 0 , s = 0 , p = 0 ;
        for (int i = 0; i < str.length(); i++) {
            if(str.charAt(i) == 'a')
                a++;
            if(str.charAt(i) == 's')
                s++;
            if(str.charAt(i) == 'p')
                p++;
        }
        System.out.println(a+" "+s+" "+p);
    }
}