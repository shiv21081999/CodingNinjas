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

int* lowestPrimeDivisor(int n)
{
	int *arr = new int[n+1];
	for (int i = 0; i < n+1; i++)
	{
		arr[i] = i;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if(arr[i] == i)
		{
			int temp = i*i;
			while(temp <= n)
			{
				if(arr[temp]==temp)
				{
					arr[temp] = i;
					
				}
				temp+=i;
			}
		}
	}
	return arr;
}

int32_t main(){
	int n;
	cin>>n;
	vector<bool> arr(n+1, false);
	int *lowestPrime = lowestPrimeDivisor(n);
	int i = n;
	vector<int> ans;
	while(i >= 1)
	{
		if(arr[i])
		{
			i--;
			continue;
		}
		ans.clear();
		int r = i;
		int m = i;
		ans.pb(i);
		arr[i] = true;
		while(r>1)
		{
			int prime = lowestPrime[r];
			m = i-prime;
			while(m > 1)
			{
				if(!arr[m])
				{
					arr[m] = true;
					ans.pb(m);
				}
				m-=prime;
			}
			while(r > 1 && r % prime == 0)
			{
				r/=prime;
			}
		}
		sort(ans.begin(), ans.end(), greater<int>());
		for (int i = 0; i < ans.size(); i++)
		{
			cout<<ans[i]<<" ";
		}
		i--;
	}
	
	return 0;
}