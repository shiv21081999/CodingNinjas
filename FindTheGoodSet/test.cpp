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
int seivearr[750001];

void seive()
{
	for (int i = 1; i < 750001; i++)
	{
		if(seivearr[i] >=1)
		{
			// cout<<i<<" ";
			int temp = i+i;
			while(temp <= 750001)
			{
				if(seivearr[temp]!=-1)
				{
					seivearr[temp]+=(seivearr[i]%mod);
					seivearr[temp]%=mod;
				}
				temp+=i;
			}
		}
	}
	
}

int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(seivearr, -1, sizeof(seivearr));
		int max = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin>>x;
			if(x > max)
				max = x;
			seivearr[x] = 1;
		}
		int ans = 0;
		seive();
		for (int i = 0; i < 750001; i++)
		{
			if(seivearr[i] != -1)
			{
				ans += (seivearr[i]%mod);
				ans %= mod;
			}
			// cout<<seivearr[i]<<" ";
		}
		// cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}