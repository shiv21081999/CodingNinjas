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

bool isPossible(unordered_map<int, int> factorsK, unordered_map<int, int> factorsarr)
{
	if(factorsarr.size() < factorsK.size())
		return false;
	for (auto x : factorsK)
	{		
		if(factorsarr[x.F]<x.S)
			return false;
	}
	return true;
}

void factorize1(int n, int mode, unordered_map<int,int> &factors)
{
	int count = 0;
	while(n%2==0 && n > 1 && factors.find(2)!= factors.end())
	{
		count++;
		n/=2;
	}
	if(mode == 0 && count!=0)
		factors[2]+=count;
	else if(factors.find(2)!=factors.end() && factors[2]!=0)
		factors[2]-=count;
	if(n>1)
	{
		for (int i = 3; i*i <= n; i+=2)
		{
			count = 0;
			while(n%i == 0 && n>1 && factors.find(i)!=factors.end())
			{
				count++;
				n/=i;
			}
			if(mode && factors.find(i)!=factors.end() && factors[i]!=0)
				factors[i]-=count;
			else if(count != 0)
				factors[i]+=count;
		}
	}
	
	if(n>1)
	{
		if(mode && factors.find(n)!=factors.end() && factors[n]!=0)
			factors[n]-=1;
		else
			factors[n]+=1;
	}
}

void factorize(int n, int mode, unordered_map<int, int> &factors)
{
	int count = 0;
	while(n%2==0 && n > 1)
	{
		count++;
		n/=2;
	}
	if(mode == 0 && count!=0)
		factors[2]+=count;
	else if(factors.find(2)!=factors.end() && factors[2]!=0)
		factors[2]-=count;
	if(n>1)
	{
		for (int i = 3; i*i <= n; i+=2)
		{
			count = 0;
			while(n%i == 0 && n>1)
			{
				count++;
				n/=i;
			}
			if(mode && factors.find(i)!=factors.end() && factors[i]!=0)
				factors[i]-=count;
			else if(count != 0)
				factors[i]+=count;
		}
	}
	
	if(n>1)
	{
		if(mode && factors.find(n)!=factors.end() && factors[n]!=0)
			factors[n]-=1;
		else
			factors[n]+=1;
	}

}

int32_t main(){
	int n, k;
	cin>>n>>k;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	int i = 0 , j = 0;
	unordered_map<int, int> factorsK;
	unordered_map<int, int> factorsarr;
	int count = 0;
	factorize(k, 0, factorsK);
	// for (auto x : factorsK)
	// {
	// 	cout<<x.F<<" "<<x.S<<endl;
	// }
	// cout<<endl;
	for (auto x : factorsK)
	{
		factorsarr[x.F] = 0;
	}
	
	int flag = true;
	while(i < n && j <n)
	{
		if(flag)
			factorize1(arr[j], 0, factorsarr);
		// for (auto x : factorsarr)
		// {
		// 	cout<<x.F<<" "<<x.S<<endl;
		// }
		// cout<<endl;
		flag = true;
		if(isPossible(factorsK, factorsarr))
		{
			count+=(n-j);
			// cout<<"DELETE"<<endl;
			factorize1(arr[i], 1, factorsarr);
			// for (auto x : factorsarr)
			// {
			// 	cout<<x.F<<" "<<x.S<<endl;
			// }
			// cout<<endl;
			flag = false;
			i++;

		}
		else
			j++;
	}
	cout<<count<<endl;
	return 0;
}