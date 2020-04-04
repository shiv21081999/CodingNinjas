import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int x = sc.nextInt();
        int[] count = new int[1026];
        int[] secCount = new int[1026];
        Arrays.fill(count,0);
        for (int i = 0; i < n; i++) {
            int index = sc.nextInt();
            count[index]++;
        }
        // System.out.println(Arrays.toString(count));
        for (int i = 0; i < k; i++) {
            int covered = 0;
            for (int j = 0; j <= 1025; j++) {
                if(count[j] > 0 )
                {
                    int index = j^x;
                    int range = count[j]/2;
                    if(covered % 2 ==0)
                    {
                        if(count[j]%2==1)
                            range++;
                    }
                    covered += count[j];
                    secCount[j]+=(count[j]-range);
                    secCount[index]+=range;
                }
            }
            count = secCount.clone();
            Arrays.fill(secCount, 0);
            // System.out.println(Arrays.toString(count));
        }
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        int r = 1;
        for (int i = 0; i < 1026; i++) {
            if(count[i] >0 && r == 1)
            {
                min = i;
                r = 0;
            }
            if(count[i] > 0)
                max = i;
        }
        System.out.println(max+" "+min);
    }
}