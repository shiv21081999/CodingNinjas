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

int gcd(int a, int b)
{
	// cout<<a<<endl;
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int32_t main(){
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		string b;
		cin>>a>>b;
		if(a==0)
		{
			cout<<b<<endl;
			continue;
		}
		int modulo = 0;
		for (int i = 0; i < b.length(); i++)
		{
			modulo = ((modulo*10)%a + (b[i]-48))%a;
		}
		if(modulo == 0)
		{
			cout<<a<<endl;
			continue;
		}
		// cout<<modulo<<endl;3
		cout<<gcd(a,modulo)<<endl;
	}
	return 0;
}