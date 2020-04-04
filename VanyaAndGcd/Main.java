import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
    static long[][] dp = new long[501][101];
    static int mod = 1000000007;
    static int gcd(int a, int b)
    {
        if(b==0)
            return a;
        return gcd(b, a%b);
    }
    static long getNoOfSequences(int[] arr)
    {
        dp[0][arr[0]] = 1;
        long res = dp[0][1];
        for (int i = 1; i < arr.length; i++) {
            for (int j = i-1; j >= 0; j--) {
                if(arr[i] > arr[j])
                {
                    for (int k = 1; k <= 100; k++) {
                        int temp = gcd(arr[i],k); 
                        dp[i][temp] += dp[j][k];
                        dp[i][temp]%= mod;
                    }
                }
            }
            dp[i][arr[i]]++;
            res += dp[i][1];
            res %= mod;
        }
        return res;
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        long ans = getNoOfSequences(arr);
        System.out.println(ans);
    }
}