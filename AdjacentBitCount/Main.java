import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
    static int mod = 1000000007;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        long[][][] dp = new long[10000][101][2];
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;
        for (int i = 2; i < dp.length; i++) {
            for (int j = 0; j < 101; j++) {
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1])%mod;
                dp[i][j][1] = (dp[i-1][j][0])%mod;
                if(j-1>=0)
                    dp[i][j][1] += (dp[i-1][j-1][1]%mod);
                dp[i][j][1] %= mod;
            }
        }
        while(t>0)
        {
            int sno = sc.nextInt();
            int n = sc.nextInt();
            int k = sc.nextInt();
            long ans = (dp[n][k][0] + dp[n][k][1])%mod;
            System.out.println(sno+" "+ans);
            t--;
        }
        
    }
}