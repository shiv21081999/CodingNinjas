/*
	In this question preprocessing is important otherwise it will give TLE :)
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
	int arr[1000001];
	for (int i = 0; i < 1000001; i++)
	{
		arr[i] = i;
	}

	seive(arr, 1000000);
	int *res = new int[1000001]();
	for (int i = 1; i < 1000001; i++)
	{
		for (int j = 2; i*j <= 1000000; j++)
		{
			// cout<<"here"<<endl;
			res[i*j]+= (i*arr[j]);
		}
		
	}
	int sum = res[0];
	arr[0] = 0;
	for (int i = 1; i <= 1000000; i++)
	{
		arr[i] = sum+res[i];
		sum+=res[i];
	}
	while(true)
	{
		int n;
		cin>>n;
		if(n==0)
			break;
		cout<<arr[n]<<endl;
		// delete [] res;
	}
	delete [] res;
	return 0;
}