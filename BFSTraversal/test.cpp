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

void printBFS(int** edges, int n, int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for (int i = 0; i < n; i++)
        {
            if(i==node)
                continue;
            if(edges[node][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
        
    }
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }
    
}

int32_t main(){
    int n, e;
    cin>>n>>e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
        
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    BFS(edges, n);
    return 0;
}