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
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int32_t main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}