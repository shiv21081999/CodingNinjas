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

int modularExponentiation(int a, string b, int m)
{
	int res = 1;
	for (int i = b.length() - 1; i >= 0; i--)
	{
		if(b[i] == '1')
		{
			res = ((res%m)*(a%m))%m;
		}
		else if(b[i] == '2')
		{
			res = ((res%m)*(a%m)*(a%m))%m;
		}
		a = ((a%m)*(a%m)*(a%m));
	}
	return res;
}

int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int a,m;
		string b;
		cin>>a;
		cin>>b;
		cin>>m;
		int ans = modularExponentiation(a, b, m);
		cout<<ans<<endl;
	}
	return 0;
}