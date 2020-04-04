#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int n;
bool tell[50];
int dp[30][30];
int getTotalSquareBracket(int o, int c , int i)
{
	if(o == n && c == n)
		return 1;
	if(o > n || c > n)
		return 0;
	if(dp[o][c] != -1)
		return dp[o][c];
	if(o == c || tell[i])
	{
		return dp[o][c] = getTotalSquareBracket(o+1,c, i+1);
	}
	else if(o == n)
	{
		return dp[o][c] = getTotalSquareBracket(o,c+1,i+1);
	}
	else
		return dp[o][c] = getTotalSquareBracket(o+1,c,i+1) + getTotalSquareBracket(o,c+1,i+1);
}
int32_t main(){
	int t;
	cin>>t;
	while(t)
	{
		int k;
		cin>>n>>k;
		// cout<<"n : "<<n<<endl;
		memset(tell, false, sizeof(tell));
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < k; ++i)
		{
			int temp;
			cin>>temp;
			// cout<<"k : "<<temp<<endl;
			tell[temp-1] = true;
		}
		// for (int i = 0; i < 50; ++i)
		// {
		// 	cout<<tell[i]<<" ";
		// }
		// cout<<endl;
		cout<<getTotalSquareBracket(0,0,0)<<endl;
		t--;
	}
}