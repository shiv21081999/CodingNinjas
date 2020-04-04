import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] arr = new int[n][n];
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        long sum = 0;
        int i = 0,j=0;
        while(i<arr.length && j<arr.length)
        {
            sum += arr[i++][j++];
        }
        i=arr.length-1;
        j=0;
        while(i>=0 && j<arr.length)
        {
            if(i!=j)
                sum += arr[i][j];
            i--;
            j++;
        }
        i = 1;
        j = 0;
        int k = arr.length-1;
        while(i<arr.length-1)
        {
            sum += arr[i][j];
            sum += arr[i][k];
            i++;
        }
        i = 0;
        j = 1;
        k = arr.length-1;
        while(j<arr.length-1)
        {
            sum += arr[k][j];
            sum += arr[i][j];
            j++;
        }
        System.out.println(sum);
        
    }
}