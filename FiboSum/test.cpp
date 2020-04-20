#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;

vector<vector<int>> prod(vector<vector<int>> res, vector<vector<int>> arr)
{
	vector<vector<int>> ans = {{0,0,0},{0,0,0},{0,0,0}};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				ans[i][j] = ((ans[i][j])%mod + ((res[i][k]%mod)*(arr[k][j]%mod))%mod)%mod;
			}
			
		}
		
	}
	return ans;
}

vector<vector<int>> getSum(int n)
{
	n--;
	vector<vector<int>> arr = {{1,1,1},{0,1,1},{0,1,0}};
	vector<vector<int>> res = {{1,0,0},{0,1,0},{0,0,1}};
	while(n > 0)
	{
		if(n&1)
		{
			res = prod(res, arr);
		}
		arr = prod(arr, arr);
		n=n>>1;
	}
	return res;
}

int fiboSum(int m , int n)
{
	if(m > 1 && n > 1)
	{
		vector<vector<int>> summ = getSum(m);
		vector<vector<int>> sumn = getSum(n);
		int f = ((summ[0][0]%mod)+ (summ[0][1]%mod))%mod;
		int s = ((sumn[0][0]%mod)+ (sumn[0][1]%mod))%mod;
		return (s - f + summ[1][1])%mod;
	}
	else if(m <= 1)
	{
		if(n<=1)
		{
			return n-m;
		}
		vector<vector<int>> sumn = getSum(n);
		int s = ((sumn[0][0]%mod)+ (sumn[0][1]%mod))%mod;
		return s;
	}

	return 0;
}

int32_t main(){
	unsigned long long m,n;
    cin>>m>>n;
	cout<<fiboSum(m,n);
	return 0;
}