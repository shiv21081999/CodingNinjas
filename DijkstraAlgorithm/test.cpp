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


int getMinIndex(bool *visited, int *dist, int n)
{
    int min = -1;
    int weight = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i] && weight > dist[i])
        {
            min = i;
            weight = dist[i];
        }
    }
    return min;
}

void getMinPath(int **edges, int n, bool *visited)
{
    int *parent = new int[n];
    int *dist = new int[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    parent[0] = -1;
    dist[0] = 0;
    for (int i = 0; i < n-1; i++)
    {
        int minVertex = getMinIndex(visited, dist, n);
        visited[minVertex] = true;
        for (int i = 0; i < n; i++)
        {
            if(!visited[i] && edges[minVertex][i] !=0)
            {
                if(dist[minVertex]+edges[minVertex][i] < dist[i])
                {
                    dist[i] = dist[minVertex]+edges[minVertex][i];
                    parent[i] = minVertex;
                }
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
        
    }
    
    
}

int32_t main(){
    int n, e;
    cin>>n>>e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++){
        edges[i] = new int[n];
    }
    for (int i = 0; i < e; i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s] = w;
        edges[s][f] = w;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    getMinPath(edges, n, visited);
    return 0;
}