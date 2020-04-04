#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define mod 1000000007  
const int N = 100005, M = 11;
int dp[51][51];
int smallestSuperSequence1(char a[] , int len1, char b[], int len2)
{
	if(len1 == 0)
		return len2;
	if(len2 == 0)
		return len1;
	if(dp[len1][len2]!= -1)
		return dp[len1][len2];
	if(a[0] == b[0])
		return dp[len1][len2] = 1 + smallestSuperSequence1(a+1, len1-1, b+1 ,len2 -1);
	else
	{
		return dp[len1][len2] = 1 + min(smallestSuperSequence1(a+1, len1-1, b, len2),smallestSuperSequence1(a, len1, b+1, len2-1));
	}
}
int smallestSuperSequence(char a[], int len1, char b[], int len2) { 
	memset(dp, -1, sizeof(dp));
	return smallestSuperSequence1(a, len1, b, len2);
}
int32_t main(){
	char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout<<min_len;
    return 0;
}