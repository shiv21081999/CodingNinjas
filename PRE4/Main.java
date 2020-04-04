import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        int groups = 0,left = 0;
        for (int i = 0; i < arr.length/2; i++) {
            int sum = arr[i]+arr[n-i-1];
            System.out.println(sum/10+" "+sum%10);
        }
    }
}