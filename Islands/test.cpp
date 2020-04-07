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
void dfs(bool **edges, int n, bool *visited, int s)
{
    visited[s] = true;
    for (int i = 1; i <= n; i++)
    {
        if(i == s)
            continue;
        if(edges[s][i] && !visited[i])
        {
            dfs(edges, n, visited, i);
        }
    }
    
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	bool *visited = new bool[n+1];
    int count = 0;
    bool **edges = new bool*[n+1];
    for (int i = 0; i <= n; i++)
    {
        edges[i] = new bool[n];
        for (int j = 0; j <= n; j++)
        {
            edges[i][j] = false;
        }
        
    }
    for (int i = 0; i < m; i++)
    {
        edges[u[i]][v[i]] = true;
        edges[v[i]][u[i]] = true;
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(edges, n, visited,i);
            count++;
        }
    }
    return count;
}
int32_t main(){
    int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
    return 0;
}