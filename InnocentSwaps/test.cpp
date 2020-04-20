/*
In this code we have to use printf and scanf to print and scan the input and output resp :)
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

int modularExponentiation(int a, int b, int m)
{
	int res = 1;
	while(b > 0)
	{
		if(b&1)
		{
			res = (res * a)%mod;
		}
		a = (a*a)%mod;
		b = b>>1;
	}
	return res;
}

void factMod(int *factmod)
{
	factmod[0] = 1;
	int fact = 1;
	for (int i = 1; i <= 1000000; i++)
	{
		fact = (fact*i)%mod;
		factmod[i] = fact;
	}
	
}

void factInvMod(int *factinvmod, int *factmod)
{
	factinvmod[0] = 1;
	for (int i = 1; i < 1000001; i++)
	{
		factinvmod[i] = modularExponentiation(factmod[i], mod-2, mod);
	}
	
}

int32_t main(){
	int *factmod = new int[1000001];
	int *factinvmod = new int[1000001];
	factMod(factmod);
	factInvMod(factinvmod, factmod);
	int t;
	scanf("%lli",&t);
	while(t--){
		int n,k;
		scanf("%lli%lli", &n,&k);
		int mul = modularExponentiation(2,k,mod);
		int mul1 = factmod[n];
		int mul2 = factinvmod[n-k];
		int mul3 = factinvmod[k];
		int ans = ((((mul%mod)*(mul1%mod))%mod)*(((mul2%mod)*(mul3%mod))%mod))%mod;
		printf("%lli\n",ans);
	}
	delete [] factmod;
	delete [] factinvmod;
	return 0;
}