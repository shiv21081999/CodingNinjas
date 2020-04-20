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
bool seive[1000001];
void seive_of_erathostene(int n)
{
	memset(seive, true, sizeof(seive));
	seive[0] = false;
	seive[1] = false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if(seive[i] == true)
		{
			int temp = i*i;
			while(temp <= n)
			{
				seive[temp] = false;
				temp+=i;
			}
		}
	}
	
}
int32_t main(){
	int n;
	cin>>n;
	seive_of_erathostene(n);
	int count = 0;
	for (int i = 0; i <=n; i++)
	{
		if(seive[i] == true)
			count++;
	}
	cout<<count<<endl;
	return 0;
}