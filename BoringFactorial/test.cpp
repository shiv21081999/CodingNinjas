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

int exponentiation(int a, int n, int p)
{
	int res = 1;
	while(n > 0)
	{
		if(n&1)
		{
			res = ((res%p)*(a%p))%p;
		}
		a = ((a%p)*(a%p))%p;
		n = n>>1;
	}
	return res;
}

int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n, p;
		cin>>n>>p;
		if(n >= p)
		{
			cout<<0<<endl;
			continue;
		}
		int i = n+1;
		int ans = -1;
		while(i <= p-1)
		{
			ans = ans*(exponentiation(i,p-2,p))%p;
			i++;
		}
		ans = (ans+p)%p;
		cout<<ans<<endl;
	}
	return 0;
}