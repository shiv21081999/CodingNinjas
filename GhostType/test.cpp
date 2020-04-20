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

int getPermute(int n, int mask)
{
	cout<<mask<<endl;
	if(mask == (1<<(n))-1)
	{
		return 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if(!(mask&(1<<i)))
		{
			for (int j = 1; j <= n; j++)
			{
				if(i&j == i && !(mask&(1<<j)))
				{
					ans += getPermute(n, mask|(1<<i));
				}
			}
			
		}
	}
	return ans;
	
}

int32_t main(){
	int n;
	cin>>n;
	cout<<getPermute(n, 0)<<endl;
	return 0;
}