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

void zfunction(string str, int *z, int n)
{
	int l = 0, r = 0;
	for (int i = 1; i < n; i++)
	{
		if(i > r)
		{
			l = i;
			r = i;
			while(r < n && str[r - l] == str[r])
			{
				r++;
			}
			z[i] = r-l;
			r--;
		}
		else
		{
			int k = i - l;
			if(z[k] + i<= r)
			{
				z[i] = z[k];
			}
			else
			{
				l = i;
				while(r < n && str[r-l] == str[r])
				{
					r++;
				}
				z[i] = r - l;
				r--;
			}
			
		}
		
	}
	
}

void printStringCommon(string str, string pattern)
{
	string combine = pattern + "$" + str;

	int *Z = new int[combine.length()]();
	zfunction(combine, Z, combine.length());
	for (int i = 0; i < combine.length(); i++)
	{
		if(Z[i] == pattern.length())
		{
			cout<<i-pattern.length()-1<<endl;
		}
	}
	
}

int32_t main(){
	string str;
	string pattern;
	cin>>str>>pattern;
	printStringCommon(str, pattern);
	return 0;
}