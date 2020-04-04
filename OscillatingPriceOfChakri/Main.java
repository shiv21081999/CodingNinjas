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
        int minSofar = arr[0];
        int maxProfit = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            if(minSofar>arr[i])
                minSofar = arr[i];
            if(arr[i] - minSofar > maxProfit)
                maxProfit = arr[i] - minSofar;
        }
        System.out.println(maxProfit);
    }
}