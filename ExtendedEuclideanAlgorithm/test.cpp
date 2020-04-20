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

Triplet extendedEuclidAlgorithm(int a, int b)
{
	if(b == 0)
	{
		Triplet temp;
		temp.gcd = a;
		temp.x = 1;
		temp.y = 0;
		return temp;
	}
	Triplet smallans = extendedEuclidAlgorithm(b, a%b);
	Triplet ans;
	ans.gcd = smallans.gcd;
	ans.x = smallans.y;
	ans.y = smallans.x - ((a/b)*smallans.y);
	return ans;
}

int32_t main(){
	int a, b;
	cin>>a>>b;
	Triplet ans = extendedEuclidAlgorithm(a,b);
	cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd<<endl;
	return 0;
}