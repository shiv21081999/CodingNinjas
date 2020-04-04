import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int [][]arr = new int[n+1][m+1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        int ans[][] = new int[n+1][m+1];
        Arrays.fill(ans[1],1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(arr[i][j] >= arr[i-1][j])
                    ans[i][j] = ans[i-1][j];
                else
                    ans[i][j] = i;
            }
        }
        int[] range = new int[n+1];
        range[0] = 0;
        range[1] = 1;
        // for (int i = 0; i < ans.length; i++) {
        //     System.out.println(Arrays.toString(ans[i]));
        // }
        for (int i = 2; i < range.length; i++) {
            int temp = Integer.MAX_VALUE;
            for (int j = 1; j < m+1; j++) {
                if(ans[i][j] < temp)
                    temp = ans[i][j];
            }
            range[i] = temp;
        }
        int t  = sc.nextInt();
        while(t>0)
        {
            int l = sc.nextInt();
            int r = sc.nextInt();
            if(range[r] <=l)
                System.out.println("Yes");
            else
                System.out.println("No");
            t--;
        }
        
    }
}