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
/*
	This code shold not be implemented using grpah :)
*/
int32_t main(){
	int n, t;
	cin>>n>>t;
	int *arr = new int[n];
	for (int i = 1; i < n; i++)
	{
		cin>>arr[i];
	}
	// vecotr<int> *edges = new vector<int>[n];
	int i = 1;
	while(i<=n)
	{
		if(i==t)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		if(i == n)
			break;
		i = i+arr[i];
	}
	cout<<"NO"<<endl;
	return 0;
}