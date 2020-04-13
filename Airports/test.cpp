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

struct Edge{
	int start;
	int end;
	int weight;
};

int root(int *parent ,int node)
{
	if(parent[node] == node)
		return node;
	parent[node] = parent[parent[node]];
	return root(parent, parent[node]);
}

void union_find(int *parent, int *rank, int a, int b)
{
	int roota = root(parent, a);
	int rootb = root(parent, b);
	if(rank[roota] > rank[rootb])
	{
		parent[rootb] = roota;
	}
	else if(rank[roota] < rank[rootb])
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
	int index = 1;
	while(t--){
		int n,e,a;
		cin>>n>>e>>a;
		Edge *edges = new Edge[e];
		for (int  i = 0; i < e; i++)
		{
			int f,s,w;
			cin>>f>>s>>w;
			edges[i].start = f-1;
			edges[i].end = s-1;
			edges[i].weight = w;
		}
		sort(edges, edges + e, [&](Edge a, Edge b){
			return a.weight < b.weight;
		});
		int *parent = new int[n];
		int *rank = new int[n];
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
		int cost = 0;
		for (int i = 0; i < e; i++)
		{
			if(edges[i].weight < a)
			{
				int ps = root(parent, edges[i].start);
				int pe = root(parent, edges[i].end);
				if(ps != pe)
				{
					union_find(parent, rank, edges[i].start, edges[i].end);
					cost += edges[i].weight;
				}
			}
			else
			{
				break;
			}
			
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if(parent[i] == i)
			{
				count++;
			}
		}
		cost += (a*count);
		cout<<"Case #"<<index++<<": "<<cost<<" "<<count<<endl;
		delete [] edges;
		delete [] parent;
		delete [] rank;
	}
	return 0;
}