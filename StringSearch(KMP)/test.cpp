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

int* getlps(char pattern[], int n)
{
	int *lps = new int[n];
	int i = 1;
	int j = 0;
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

int findString(char s[], char t[]) {
	int n = strlen(t);
	int *lps = getlps(t, n);
	int i = 0, j = 0;
	int start = 0;
	int m = strlen(s);
	while(i < m && j < n)
	{
		if(s[i] == t[j])
		{
			i++;
			j++;
		}
		else{
			if(j!=0)
			{
				j = lps[j-1];
				start = i - j;
			}
			else
			{
				i++;
				start = i;
			}
			
		}
		if(j == n)
			return start;
	}
	return -1;
}

int32_t main(){
	char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
	return 0;
}