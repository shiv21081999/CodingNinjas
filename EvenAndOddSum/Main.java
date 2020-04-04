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
        long even = 0 , odd = 0;
        for (int i = 0; i < arr.length; i++) {
            if(arr[i]%2 == 0 && i%2 ==0)
                even += arr[i];
            else if(arr[i]%2 != 0 && i%2 != 0)
                odd += arr[i];
        }
        System.out.println(even+" "+odd);
    }
}