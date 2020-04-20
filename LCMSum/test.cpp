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

void func(int n)
{
	int sum = 0;
	for (int i = 1; i < n+1; i++)
	{
		sum+=((n*i)/__gcd(i,n));
	}
	cout<<sum<<endl;
}

int32_t main(){
	long long n;
    scanf ( "%lld", &n );
	func(n);
	return 0;
}