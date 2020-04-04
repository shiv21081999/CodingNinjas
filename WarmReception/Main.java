import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int[] dep = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        for (int i = 0; i < arr.length; i++) {
            dep[i] = sc.nextInt();
        }
        Arrays.sort(arr, 0, n);
        Arrays.sort(dep, 0, n);
        int i = 1,j=0;
        int chairs = 1,res = 1;
        while(i<arr.length && j<dep.length)
        {
            if(arr[i] <= dep[j])
            {
                chairs++;
                if(chairs > res)
                    res = chairs;
                i++;
            }
            else
            {
                chairs--;
                j++;
            }
        }
        // System.out.println(Arrays.toString(arr));
        // System.out.println(Arrays.toString(dep));
        System.out.println(res);
    }
}