import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] arr  = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        long old_cost = 0 , new_cost = 0,target = 0;
        target = 0;
        int sum = arr[0];
        for (int j = 1; j < k; j++) {
            target += (j*arr[j] - sum);
            sum+= arr[j];
        }
        // System.out.println(target);
        // System.out.println(sum);
        old_cost = target;
        for (int i = k; i < arr.length; i++) {
            // System.out.println(arr[i]);
            new_cost = old_cost + (-2*(sum-arr[i-k])) + (k-1)*arr[i-k] + (k-1)*arr[i];
            // System.out.println(new_cost+" "+arr[i-k]+" "+arr[i]+" "+i);
            if(new_cost < target)
                target = new_cost;
            old_cost = new_cost;
            sum-=arr[i-k];
            sum+=arr[i];
        }
        System.out.println(target);
    }
}