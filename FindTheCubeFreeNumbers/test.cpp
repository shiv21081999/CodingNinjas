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
bool seivearr[1000001];
unordered_map<int, int> cubefree;
void seive()
{
	memset(seivearr, true, sizeof(seivearr));
	seivearr[0] = false;
	for (int i = 2; i*i*i <= 1000000; i++)
	{
		if(seivearr[i])
		{
			int temp = i*i*i;
			for (int j = i*i*i; j <= 1000000; j+=temp)
			{
				seivearr[j] = false;
			}
			
		}
	}
	int k = 1;
	for (int i = 0; i < 1000001; i++)
	{
		if(seivearr[i])
			cubefree[i] = k++;
	}
	
	
}
int32_t main(){
	int t;
	cin>>t;
	seive();
	int i = 1;
	while(t--){
		int n;
		cin>>n;
		if(cubefree.find(n)!=cubefree.end())
		{
			cout<<"Case "<<i++<<": "<<cubefree[n]<<endl;
		}
		else
		{
			cout<<"Case "<<i++<<": NotCubeFree"<<endl;
		}
		
	}
	
	return 0;
}