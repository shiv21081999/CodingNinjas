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

class Triplet{
	public:
		int b;
		int q;
		int gcd;
};

Triplet moduloInverse(int a, int m)
{
	if(m == 0)
	{
		Triplet ans;
		ans.gcd = a;
		ans.b = 1;
		ans.q = 0;
		return ans;
	}
	Triplet smallans = moduloInverse(m, a%m);
	Triplet ans;
	ans.gcd = smallans.gcd;
	ans.b = smallans.q;
	ans.q = smallans.b - ((a/m)*smallans.q);
	return ans;
}

int32_t main(){
	int a,m;
	cin>>a>>m;
	Triplet ans = moduloInverse(a,m);
	if(ans.gcd == 1)
		cout<<(m+ans.b)%m<<endl;
	else
		cout<<"No solution"<<endl;
	return 0;
}