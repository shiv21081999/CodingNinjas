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
int solveFact(int n, int m)
{
	int ans = 1;
	while(n > 0)
	{
		ans = (ans * n)%m;
		n--;
	}
	return ans;
}
int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int T, m;
		cin>>T>>m;
		if(T < m)
		{
			int ans = solveFact(T,m);
			cout<<ans<<endl;
		}
		else if((T/m)%2==0)
		{
			int ans = solveFact(T%m,m);
			cout<<ans<<endl;
		}
		else
		{
			int ans = (solveFact(T%m,m)*(m-1))%m;
			cout<<ans<<endl;
		}
		
	}
	return 0;
}