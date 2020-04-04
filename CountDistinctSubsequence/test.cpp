#include<bits/stdc++.h>
#include<string>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
int mod = 1000000007;
const int N = 100005, M = 11;
unordered_set<string> sn;
int dp[100005];
int alpha[256];
int getSubsequence(char str[], int n)
{
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = ((2%mod)*(dp[i-1]%mod))%mod;
		if(alpha[str[i-1]] !=-1)
			dp[i] -= (dp[alpha[str[i-1]]]%mod);
		dp[i] = (dp[i]+mod)%mod;
		alpha[str[i-1]] = i-1;
	}
	return dp[n];
}
int32_t main(){
	int t;
	cin>>t;
	while(t)
	{
		char str[100005];
		cin>>str;
		char ans[100005];
		int n = strlen(str);
		// cout<<n<<" "<<str<<endl;
		memset(alpha, -1, sizeof(alpha));
		int finalans = getSubsequence(str,n);
		cout<<finalans<<endl;
		
		t--;
	}
}