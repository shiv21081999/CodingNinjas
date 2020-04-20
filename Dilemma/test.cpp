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

#include<bits/stdc++.h>
int solve(int pos, int mask, vector<string> v, int **dp)
{
    if((mask&(mask-1))==0)
        return 0;
    if(pos < 0)
        return 10000;
	int newmask1 = 0;
	int newmask2 = 0;
	int touch = 0;
	// cout<<pos<<endl;
    if(dp[pos][mask] != INT_MAX)
        return dp[pos][mask];
	for (int i = 0; i < v.size(); i++)
	{
		if(mask&(1<<i))
		{
			touch++;
			if(v[i][pos] == '0')
			{
				newmask1 |= (1<<i);
			}
			else
			{
				newmask2 |= (1<<i);
			}
        }
			
	}
	int ans1 = solve(pos -1, newmask1, v, dp) + solve(pos-1, newmask2, v, dp)+touch;
	int ans2 = solve(pos-1, mask, v, dp);
	return dp[pos][mask] = min(ans1, ans2);
	
}

int minimumTouchesRequired(int n, vector<string> v)
{
	int **dp = new int*[v[0].size()];
	for (int i = 0; i < v[0].size(); i++)
	{
		dp[i] = new int[1<<(n+1)];
		for (int j = 0; j < 1<<(n+1); j++)
		{
			dp[i][j] = INT_MAX;
		}
		
	}
	return solve(v[0].size()-1, (1<<n)-1, v, dp);
}

int32_t main(){
	int n;
    
    vector<string> v;
    
	cin >> n;
	for(int i = 0; i < n; i++) {
		string a;
		cin >> a;
		v.push_back(a);
	}
	cout << minimumTouchesRequired(n, v) << endl;
	return 0;
}