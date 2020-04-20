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
int mod1 = 1000000006;
void prod(int a[2][2], int m[2][2])
{
	int f,g,h,i;
 
    f = ( (a[0][0] * m[0][0]) %mod1 + (a[0][1] * m[1][0]) %mod1 )%mod1;
    g = ( (a[0][0] * m[0][1]) %mod1 + (a[0][1] * m[1][1]) %mod1 )%mod1;
    h = ( (a[1][0] * m[0][0]) %mod1 + (a[1][1] * m[1][0]) %mod1 )%mod1;
    i = ( (a[1][0] * m[0][1]) %mod1 + (a[1][1] * m[1][1]) %mod1 )%mod1;
	a[0][0] = f;
    a[0][1] = g;
    a[1][0] = h;
    a[1][1] = i;
}

void fib(int res[2][2], int mat[2][2], int n)
{
	n--;
	while(n>0)
	{
		if(n&1)
		{
			prod(res, mat);
		}
		prod(mat, mat);
		n = n>>1;
	}
	// vector<int> ans;
	// ans.pb(res[1][0]%mod1);
	// ans.pb(res[0][0]%mod1);
	// return ans;
}

int modularExponentiation(int a, int b, int m)
{
	int res = 1;
	while(b>0)
	{
		if(b&1)
		{
			res = (res* a)%m;
		}
		a = (a*a)%m;
		b = b>>1;
	}
	return res;
}

int32_t main(){
	int t;
	scanf("%lli",&t);
	while(t--){
		int a,b,n;
		scanf("%lli%lli%lli",&a,&b,&n);
		if(n==0)
		{
			printf("%lli\n",a);
			continue;
		}
		if(n==1)
		{
			printf("%lli\n",b);
			continue;
		}
		int mat[2][2] = {{1,1},{1,0}};
		int res[2][2] = {{1,0},{0,1}};
		fib(res, mat, n);
		a++;
		b++;
		int mul1 = modularExponentiation(a, res[1][0], mod);
		int mul2 = modularExponentiation(b, res[0][0], mod);
		int ans = (((mul1%mod)*(mul2%mod))%mod)-1;
		printf("%lli\n",ans);
	}
	return 0;
}