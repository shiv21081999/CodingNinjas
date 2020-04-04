import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] s = new int[n+1];
        int[] e = new int[n+1];
        int[] count = new int[n+1];
        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            s[l]++;
            e[r]++;
        }
        count[0] = s[0];
        for (int i = 1; i < n+1; i++) {
            count[i] = s[i] - e[i-1] + count[i-1];
        }
        int boxes_per_coin[] = new int[n+1];
        for (int i = 0; i < boxes_per_coin.length; i++) {
            boxes_per_coin[count[i]]++;
        }
        int[] atleast = new int[n+1];
        atleast[n] = boxes_per_coin[n];
        for (int i = n-1; i >= 0; i--) {
            atleast[i] = boxes_per_coin[i] + atleast[i+1];
        }
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int x = sc.nextInt();
            System.out.println(atleast[x]);
        }
    }
}