#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
int mod = 1000000007;
const int N = 100005, M = 11;

int numofAP(int *arr, int n){
	int ans = n+1;
	int *dp = new int[n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = 0;
	}
	int min = INT_MAX;
	int max = INT_MIN;
	int sum[1000001];
	for (int i = 0; i < n; i++)
	{
		if(arr[i]<min)
			min = arr[i];
		if(arr[i]>max)
			max = arr[i];
	}
	for (int d = min-max; d <= max - min; d++)
	{
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; i++)
		{
			dp[i] = 1;
			if(arr[i] - d >= 1 && arr[i] - d <= 1000000)
			{
				dp[i]+= sum[arr[i]-d];
			}
			ans += dp[i]-1;
			sum[arr[i]]+= dp[i];
		}
		
	}
	
	return ans;
 }

int32_t main(){
	int N;
    cin >> N;

    int *arr = new int[N+1];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << numofAP(arr, N) << endl;
	return 0;
}