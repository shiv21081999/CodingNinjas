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

this solution is based on dsu algorithm with rank and path compression :)
*/
int root(int *parent, int node)
{
	if(parent[node] == node)
	{
		return node;
	}
	parent[node] = parent[parent[node]];
	return root(parent, parent[node]);
}

void union_rank(int *parent, int *rank, int a, int b)
{
	int roota = root(parent, a);
	int rootb = root(parent, b);
	if(rank[roota] > rank[rootb])
	{
		parent[rootb] = roota;
	}
	else if(rank[rootb] > rank[roota])
	{
		parent[roota] = rootb;
	}
	else
	{
		parent[roota] = rootb;
		rank[rootb]++;
	}
	
}

int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		// vector<int>* edges = new vector<int>[n];
		int *parent = new int[n];
		int *rank = new int[n];
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
		
		for (int i = 0; i < m; i++)
		{
			int f,s;
			cin>>f>>s;
			// edges[f-1].pb(s-1);
			// edges[s-1].pb(f-1);
			union_rank(parent, rank,f-1,s-1);
		}
		int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin>>arr[i];
		}
		int *maxCoins = new int[n];
		for (int i = 0; i < n; i++)
		{
			maxCoins[i] = 0;
		}
		
		int maxans = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			int rooti = root(parent, i);
			maxCoins[rooti]+= arr[i];
			if(maxCoins[rooti]>maxans)
				maxans = maxCoins[rooti];
		}
		cout<<maxans<<endl;
		delete [] maxCoins;
		delete [] arr;
		delete [] parent;
		delete [] rank;
	}
	return 0;
}