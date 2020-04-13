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

int countPalindromeSubstrings(char s[]) {
	int n = strlen(s);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count++;
		int l = i-1;
		int	r = i+1;
		while(l>=0 && r <n)
		{
			if(s[l] == s[r])
			{
				l--;
				r++;
				count++;
			}
			else break;
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		if(s[i] == s[i+1])
		{
			int l = i-1;
			int r = i+1;
			while(l>=0 && r<n)
			{
				if(s[l] == s[r])
				{
					l--;
					r++;
					count++;
				}
				else break;
			}
		}
	}
	return count;
}


int32_t main(){
	char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
	return 0;
}