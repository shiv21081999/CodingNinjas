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

int countarr[1000001];
int dp[11][1000001];
void factorise()
{
	memset(countarr, 0, sizeof(countarr));
	for (int i = 2; i < 1000000; i++)
	{
		if(countarr[i] == 0)
		{
			countarr[i] = 1;
			int temp = i+i;
			while(temp<=1000000)
			{
				countarr[temp]++;
				temp+=i;
			}
		}
	}
	
}

void makeDp()
{
	// cout<<"here"<<endl;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j < 1000001; j++)
		{
			dp[i][j] = dp[i][j-1];
			if(countarr[j] == i)
			{
				dp[i][j]++;
			}
		}
		
	}
	
}

int32_t main(){

	factorise();
	memset(dp, 0, sizeof(dp));
	makeDp();
	int t;
	cin>>t;
	while(t--)
	{

		int a,b,n;
		cin>>a>>b>>n;
		cout<<dp[n][b]-dp[n][a-1]<<endl;
	}
	
	return 0;
}