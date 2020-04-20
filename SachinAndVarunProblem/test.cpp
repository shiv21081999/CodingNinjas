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
		int x;
		int y;
		int gcd;
};

Triplet euclideanAlgorithm(int a, int b)
{
	if(b==0)
	{
		Triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans; 
	}
	Triplet smallans = euclideanAlgorithm(b, a%b);
	Triplet ans ;
	ans.gcd = smallans.gcd;
	ans.x = smallans.y;
	ans.y = smallans.x - ((a/b)*smallans.y);
	return ans;
}

int multiplicativeModulo(int a, int m)
{
	int x = euclideanAlgorithm(a,m).x;
	return (x%m + m)%m;
}

int32_t main(){
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,d;
		cin>>a>>b>>d;
		int g = __gcd(a,b);
		if(d%g)
		{
			cout<<0<<endl;
			continue;
		}
		a/=g;
		b/=g;
		d/=g;

		if(d==0)
		{
			cout<<1<<endl;
			continue;
		}
		int x = multiplicativeModulo(b,a);
		int y1 = ((d%a)*x)%a;
		int firstValue = d/b;
		if(d >= y1*b)
		{
			int ans = (firstValue - y1)/a;
			ans++;
			cout<<ans<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
		
	}
	return 0;
}