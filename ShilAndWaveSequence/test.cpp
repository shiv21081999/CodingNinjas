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
struct node{
	int zero;
	int one;
	int two;
};
node BIT[N];

void update(int y, int val, int type)
{
	for(; y <= 100000; y += (y&(-y)))
	{
		if(type == 0)
			BIT[y].zero += (val)%mod;
		else if(type == 1)
			BIT[y].one += (val)%mod;
		else
			BIT[y].two += (val)%mod;
		BIT[y].zero %= mod;
		BIT[y].one %= mod;
		BIT[y].two %= mod;
	}
}

int query(int y, int type)
{
	int count = 0;
	for(; y>0 ;y-= (y&(-y)))
	{
		if(type == 0)
			count += BIT[y].zero%mod;
		else if(type == 1)
			count += BIT[y].one%mod;
		else
			count += BIT[y].two%mod;
		count%=mod;
	}
	return count%mod;
}

int32_t main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
		if(arr[i]>max)
			max = arr[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a = query(arr[i]-1,0) + query(arr[i]-1, 2);
		int b = (query(max, 1) - query(arr[i],1) + query(max,2) - query(arr[i],2))+mod;
		update(arr[i],a%mod,1);
		update(arr[i],b%mod,0);
		update(arr[i],1,2); 
		ans += (a + b)%mod;
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}