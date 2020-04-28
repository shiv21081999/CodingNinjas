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

int mex(int a, int b, int c)
{
	int x = max(a , max(b,c));
	for (int i = 0; i < x+2; i++)
	{
		if(i == a || i == b || i == c)
			continue;
		return i;
	}
	return -1;
}

int grundy(int n)
{
	if(n<=3)
		return n;
	return mex(grundy(n/2),grundy(n/3),grundy(n/6));
}

int32_t main(){
	int n;
	cin>>n;
	cout<<grundy(n)<<endl;
	return 0;
}