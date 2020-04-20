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

void seive(int *arr, int n)
{
	for (int i = 2; i <= n; i++)
	{
		if(arr[i] == i)
		{
			arr[i] = i-1;
			int temp = i+i;
			while(temp <= n)
			{
				arr[temp] = (arr[temp]*(i-1))/i;
				temp+=i;
			}
		}
	}
	
}

int32_t main(){
	int n;
	cin>>n;
	int *arr = new int[n+1];
	for (int i = 0; i < n+1; i++)
	{
		arr[i] = i;
	}
	seive(arr,n);
	for (int i = 1; i < n+1; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}