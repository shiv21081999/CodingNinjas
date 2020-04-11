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

void DFS(vector<int> *edges, int s, bool *visited, stack<int> &finishedVisited)
{
	visited[s] = true;
	for (int i = 0; i < edges[s].size(); i++)
	{
		int adjacent = edges[s].at(i);
		if(!visited[adjacent])
		{
			DFS(edges, adjacent, visited, finishedVisited);
		}
	}
	finishedVisited.push(s);
}

void DFS2(vector<int> *edges, bool *visited, int s)
{
	visited[s] = true;
	for (int i = 0; i < edges[s].size(); i++)
	{
		int adjacent = edges[s].at(i);
		if(!visited[adjacent])
		{
			DFS2(edges, visited, adjacent);
		}

	}
	
}

void getSCC(vector<int> *edges, vector<int> *edgesT, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
	stack<int> finishedVisited;
	for (int i = 0; i < n; i++)
	{
		if(!visited[i])
		{

			DFS(edges, i, visited, finishedVisited);
		}
	}
    
	int count = 0;
	for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
	while(!finishedVisited.empty())
	{
		int node = finishedVisited.top();
		finishedVisited.pop();
		if(!visited[node])
        {
            count++;
		    DFS2(edges, visited, node);
        }
	}
    delete [] visited;
	cout<<count<<endl;
}

int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		vector<int>* edges = new vector<int>[n];
		vector<int>* edgesT = new vector<int>[n];
		for (int i = 0; i < q; i++)
		{
			int f,s;
			cin>>f>>s;
			edges[f-1].pb(s-1);
			edgesT[s-1].pb(f-1);
		}
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<i<<"->";
        //     for (int j = 0; j < edges[i].size(); j++)
        //     {
        //         cout<<edges[i][j]<<"->";
        //     }
        //     cout<<endl;
        // }
        
		getSCC(edges, edgesT, n);
		delete [] edges;
		delete [] edgesT;
	}
	return 0;
}