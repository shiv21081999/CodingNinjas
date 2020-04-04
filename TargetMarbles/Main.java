import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        int i =0 , j = 0 , sum = 0;
        boolean flag = false;
        while(i<arr.length)
        {
            
            if(sum == target)
            {
                flag = true;
                break;
            }
            if(sum > target)
            {
                sum-= arr[i];
                i++;
                continue;
            }
            sum += arr[j];
            if(j<arr.length)
                j++;
        }
        if(flag == true)
        {
            System.out.println(true);
            for (int k = i; k < j; k++) {
                System.out.print(arr[k]+" ");
            }
        }
        else
        {
            System.out.println(false);
        }
    }
}