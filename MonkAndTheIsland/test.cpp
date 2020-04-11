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

class comp{
	public:

		int operator() (const P &a, const P &b)
		{
			return a.S>b.S;
		}
};

int getMinVertex(bool *visited, int *bridges, int n)
{
	int index = -1;
	int weight = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if(!visited[i] && weight>bridges[i])
		{
			index = i;
			weight = bridges[i];
		}
	}
	return index;
}

int dijkstra(vector<int> *edges, int n)
{
	// int *parent = new int[n];
	bool *visited = new bool[n];
	int *bridges = new int[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		bridges[i] = INT_MAX;
	}
	bridges[0] = 0;
	priority_queue<P,vector<P>,comp> pq;
	// parent[0] = -1;
	pq.push({0,0});
	while(!pq.empty())
	{
		int minv  = pq.top().F;
		pq.pop();
		visited[minv] = true;
		for (int j = 0; j < edges[minv].size(); j++)
		{
			if(!visited[edges[minv][j]])
			{
				if(bridges[minv] + 1 < bridges[edges[minv][j]])
				{
					bridges[edges[minv][j]] = bridges[minv] + 1;
					pq.push({edges[minv][j], bridges[minv] + 1});
				}
			}
		}
		

	}
	int ans = bridges[n-1];
	delete [] bridges;
	delete [] visited;
	return ans;
}

int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vector<int> *edges = new vector<int>[n];
		for (int i = 0; i < m; i++)
		{
			int f, s;
			cin>>f>>s;
			edges[f-1].pb(s-1);
			edges[s-1].pb(f-1);
		}
		int ans = dijkstra(edges, n);
		cout<<ans<<endl;
		delete [] edges;
	}
	return 0;
}