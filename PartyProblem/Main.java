import java.util.*;
import java.util.Arrays;
import java.util.Collections;
import java.math.BigInteger;
public class Main {
	static void getMaxFun(int[] fee, int[] fun , int budget)
	{
		long finalfun = 0,finalfee = 0;
		long[][] funans = new long[fee.length+1][budget+1];
		for (int i = 1 ; i <= fee.length ; i++) {
			for (int j = 1 ; j <= budget; j++) {
				if(fee[i-1] <= j)
				{
					funans[i][j] = (long) Math.max(funans[i-1][j],funans[i-1][j-fee[i-1]]+fun[i-1]);
				}
				else
				{
					funans[i][j] = funans[i-1][j];
				}
			}
		}
		finalfun = funans[fee.length][budget];
		for (int i = 1 ; i <= budget ; i++) {
			if(funans[fee.length][i] == finalfun)
			{
				finalfee = i;
				break;
			}
		}
		System.out.println(finalfee+" "+finalfun);
	}

    public static void main(String args[]) {
    	Scanner sc = new Scanner(System.in);
    	while(true)
    	{
    		int budget = sc.nextInt();
    		int n = sc.nextInt();
    		if(budget == 0 && n == 0 )
    			break;
    		int[] fee = new int[n];
    		int[] fun = new int[n];
    		for (int i = 0 ; i < n ; i++) {
    			fee[i] = sc.nextInt();
    			fun[i] = sc.nextInt();
    		}
    		// System.out.println(Arrays.toString(fee));
    		// System.out.println(Arrays.toString(fun));
    		getMaxFun(fee, fun, budget);
    	}
    }
}