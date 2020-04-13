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
	int s;
	int e;
	int w;
	int index;
};
unordered_map<int, unordered_set<int>> bridge;
int root(int *parent, int node)
{
	if(node == parent[node])
		return node;
	parent[node] = parent[parent[node]];
	return root(parent , parent[node]);
}

void union_find(int *parent, int *rank, int a, int b)
{
	int roota = root(parent, a);
	int rootb = root(parent, b);

	if(rank[roota] > rank[rootb])
		parent[rootb] = roota;
	else if(rank[rootb] > rank[roota])
		parent[roota] = rootb;
	else
	{
		parent[roota] = rootb;
		rank[rootb]++; 
	}
	
}

void bridges(vector<int> *edges, int u, bool *visited, int *disc, int *low, int *parent)
{
	// cout<<"here"<<endl;
	static int time = 0;
	visited[u] = true;
	disc[u] = low[u] = ++time;
	// cout<<time<<endl;
	// cout<<u<<" ";
	for (int i = 0; i < edges[u].size(); i++)
	{
		int v = edges[u][i];
		// cout<<v<<" ";
		if(!visited[v])
		{
			// cout<<u<<"->"<<v<<" ";
			parent[v] = u;
			bridges(edges, v, visited, disc, low, parent);
			low[u] = min(low[u], low[v]);
			if(low[v] > disc[u])
			{
				// cout<<"here"<<endl;
				bridge[u].insert(v);
			}
		}
		else if(v != parent[u])
		{
			low[u] = min(low[u], disc[v]);
			// cout<<"here"<<endl;
		}
	}
	// cout<<endl;
	
}

int32_t main(){
	int n,e;
	cin>>n>>e;
	Edge *edges = new Edge[e];
	vector<int>* list = new vector<int>[n];
	for (int i = 0; i < e; i++)
	{
		int f,s,w;
		cin>>f>>s>>w;
		edges[i].s = f-1;
		edges[i].e = s-1;
		edges[i].w = w;
		edges[i].index = i;
		list[f-1].pb(s-1);
		list[s-1].pb(f-1);
	}
	sort(edges, edges + e, [&](Edge a, Edge b){
		return a.w < b.w;
	});
	
	bool *visited = new bool[n];
	int *parent = new int[n];
	int *disc = new int[n];
	int *low = new int[n];
	int *rank = new int[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		parent[i] = -1;
		disc[i] = 0;
		low[i] = 0;
		rank[i] = 0;
	}
	parent[0] = 0;
	for (int i = 0; i < n; i++)
	{
		if(!visited[i])
			bridges(list, i, visited, disc, low, parent);
	}
	// cout<<endl;
	// for (auto it : bridge)
	// {
	// 	// cout<<"here";
	// 	int i = it.F;
	// 	cout<<i<<"->";
	// 	// unordered_set<int>::iterator it1 = ((it)->S).begin();
	// 	for(auto it1: it.S)
	// 	{
	// 		cout<<(it1)<<" ";
	// 	}
	// 	// it++;
	// 	cout<<endl;
	// }
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	int i = 0;
	int *ans = new int[e];
	while(i<e-1)
	{
		
		if(edges[i].w != edges[i+1].w)
		{
			int roots = root(parent, edges[i].s);
			int roote = root(parent, edges[i].e);
			if(roots != roote)
			{
				// cout<<"any"<<endl;
				ans[edges[i].index] = 0;
				union_find(parent, rank, roots, roote);
			}
			else if(roots == roote)
			{
				// cout<<"none"<<endl;
				ans[edges[i].index] = 2;
			}
			i++;
			continue;
		}
		else if(edges[i].w == edges[i+1].w)
		{
			int j = i;
			for (j = i; j < e-1; j++)
			{
				if(edges[j].w != edges[j+1].w)
				{
					break;
				}
			}
			bool flag = false;
			for (int k = i; k <= j; k++)
			{
				int roots = root(parent, edges[k].s);
				int roote = root(parent, edges[k].e);
				if(roots == roote)
				{
					// cout<<"none"<<endl;
					ans[edges[k].index] = 2;
				}
				else{
					if(bridge.find(edges[k].s) != bridge.end())
					{
						if(bridge[edges[k].s].count(edges[k].e) > 0)
						{
							// cout<<"any"<<endl;
							ans[edges[k].index] = 0;
							union_find(parent, rank, edges[k].s, edges[k].e);
						}
					}
					else
					{
						// cout<<"at least one"<<endl;
						ans[edges[k].index] = 1;
					}
					
				}
			}
			i = j+1;
			continue;
			
		}
		
	}
	for (i = 0; i < e; i++)
	{
		if(ans[i] == 0)
			cout<<"any"<<endl;
		else if(ans[i] == 1)
			cout<<"at least one"<<endl;
		else
			cout<<"none"<<endl;
	}
	delete [] parent;
	delete [] edges;
	delete [] list;
	delete [] rank;
	delete [] ans;
	delete [] visited;
	delete [] disc;
	delete [] low;
	return 0;
}