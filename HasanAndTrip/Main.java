import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
class City{
	double x = 0;
	double y = 0;
	double f = 0;
}
public class Main {
	static double[] dp = new double[3001];
	static double getMaxHappiness(City[] arr, int i, double happiness)
	{
		if(i==arr.length-1)
		{
			return happiness+arr[i].f;
		}
		double finalans = happiness + arr[i].f;
		happiness += arr[i].f;
		if(dp[i] > Integer.MIN_VALUE)
			return dp[i];
		for (int j = i+1; j < arr.length; j++) {
			double hp = Math.sqrt(((arr[i].x-arr[j].x)*(arr[i].x-arr[j].x))+((arr[i].y-arr[j].y)*(arr[i].y-arr[j].y)));
			// System.out.println(hp+" "+j);
			double ans = getMaxHappiness(arr, j, happiness-hp);
			if(ans > finalans)
				finalans = ans;
		}
		dp[i] = finalans;
		return finalans;
	}
	static double getMaxHappiness(City[] arr)
	{
		double[] ans = new double[arr.length];
		ans[0] = arr[0].f;
		ans[1] = arr[0].f - Math.sqrt(((arr[0].x-arr[1].x)*(arr[0].x-arr[1].x))+((arr[0].y-arr[1].y)*(arr[0].y-arr[1].y))) + arr[1].f;
		for (int i = 2; i < ans.length; i++) {
			 double finalHappiness = Integer.MIN_VALUE;
			 for (int j = i-1; j >= 0; j--) {
				 double happiness = ans[j] + arr[i].f - Math.sqrt(((arr[i].x-arr[j].x)*(arr[i].x-arr[j].x))+((arr[i].y-arr[j].y)*(arr[i].y-arr[j].y)));
				 if(happiness > finalHappiness)
				 	finalHappiness = happiness;
			 }
			 ans[i] = finalHappiness;
		}
		return ans[ans.length - 1];
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		City[] arr = new City[n];
		for (int i = 0; i < n; i++) {
			City temp = new City();
			temp.x = sc.nextDouble();
			temp.y = sc.nextDouble();
			temp.f = sc.nextDouble();
			arr[i] = temp;
		}
		Arrays.fill(dp, Integer.MIN_VALUE);
		System.out.printf("%.6f",getMaxHappiness(arr));
	}
}