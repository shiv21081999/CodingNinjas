/*
In this code please use "\n" instead of endl :)
*/
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
bool prime[N];
vector<int> primes;
void seive()
{
	int ans = 0;
	memset(prime, true, sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i < N; i++)
	{
		if(prime[i])
		{
			primes.pb(i);
			int temp = i*i;
			while(temp<N)
			{
				prime[temp] = false;
				temp+=i;
			}
		}
	}
	

	
}

int32_t main(){
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int t;
	cin>>t;
	seive();
	while(t--){
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		int l, r;
		cin>>l>>r;
		n = r-l+1;
		int *arr = new int[n];
		for (i = 0; i < n; i++)
		{
			arr[i] = l+i;
		}
		for (auto prime : primes)
		{
			if(prime*prime > r)
				break;
			int start = (l/prime)*prime;
			if(prime >= l)
				start = 2*prime;
			for(i = start ; i <= r; i+=prime)
			{
				if(i < l)
					continue;
				arr[i-l]/=prime;
			}
		}
		for (i = 0; i < n; i++)
		{
			if(i+l == arr[i] && i+l != 1)
				cout<<arr[i]<<"\n";
		}
		delete [] arr;
	}
	return 0;
}