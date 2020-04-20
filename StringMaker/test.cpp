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
int dp[51][51][51];
int solve(string a, string b, string c, int i, int j, int k)
{
	if(k==c.length())
		return 1;
	if(i >= a.length() || j >= b.length())
		return 0;
	int count = 0;
	if(dp[i][j][k] != -1)
		return dp[i][j][k];
	int x = i;
	for (x = i; x < a.length(); x++)
	{
		if(a[x] == c[k])
			count+=(solve(a,b,c,x+1,j,k+1));
	}
	
	for(x = j; x<b.length(); x++)
	{
		if(b[x] == c[k])
			count+=solve(a, b, c, i, x+1, k+1);
	}
	dp[i][j][k] = count;
	return count;
}

int solve(string a,string b,string c)
{
	memset(dp, -1, sizeof(dp));
	return solve(a,b,c,0,0,0);
}

int32_t main(){
	string a;
	string b;
	string c;
	cin>>a>>b>>c;
	// cout<<a<<" "<<b<<" "<<c<<endl;
	cout<<solve(a, b, c)<<endl;
	return 0;
}