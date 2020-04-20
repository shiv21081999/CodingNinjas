#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;
vector<int> primes;
bool seive_arr[50001];
void seive(int n)
{
	for (int i = 0; i <= 50001; i++)
	{
		seive_arr[i] = true;
	}
	
	seive_arr[0] = false;
	seive_arr[1] = false;
	for (int i = 2; i*i <= n; i++)
	{
		if(seive_arr[i])
		{
			// primes.pb(i);
			int temp = i*i;
			while (temp <= n)
			{
				seive_arr[temp] = false;
				temp+=i;
			}
			
		}
	}
	for (int i = 0; i <= n; i++)
	{
		if(seive_arr[i])
		{
			primes.pb(i);
		}
	}
	
	
}
int32_t main(){
	int t;
	cin>>t;
	seive(50000);
	// for (int i = 0; i < primes.size(); i++)
	// {
	// 	cout<<primes[i]<<" ";
	// }
	// cout<<endl;
	while(t--){
		int n;
		cin>>n;
		int ans = 1;
		for(int i = 0 ; primes[i]<=n && i < primes.size(); i++)
		{
			int prime = primes[i];
			int count = 0;
			while(prime<=n)
			{
				count+=(n/prime)%mod;
				count%=mod;
				prime*=primes[i];
			}
			ans = ((ans%mod)*((count+1)%mod))%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}