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

int* getlps(string pattern)
{
	int n = pattern.length();
	int *lps = new int[n];
	int i = 1, j = 0;
	while(i<n)
	{
		if(pattern[i] == pattern[j])
		{
			lps[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			if(j != 0)
			{
				j = lps[j-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
			
		}
		
	}
	return lps;
}

int32_t main(){
	string str;
	cin>>str;
	int *lps = getlps(str);
	for (int i = 0; i < str.length(); i++)
	{
		cout<<lps[i]<<" ";
	}
	cout<<endl;
	return 0;
}