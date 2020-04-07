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
queue<int> q;

void bfs(int **edges, queue<int>q, bool *visited, int n)
{
    int node;
    if(q.empty())
        return;
    node = q.front();
    q.pop();
    cout<<node<<" ";
    for (int i = 0; i < n; i++)
    {
        if(edges[node][i] == 1 && node !=i)
        {
            if(visited[i])
                continue;
            q.push(i);
            visited[i] = true;
        }
    }
    bfs(edges, q, visited,n);
        
}
void bfsIterative(int **edges, int sv, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    q.push(sv);
    q.push(INT_MIN);
    visited[sv] = true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        if(node == INT_MIN)
        {
            cout<<endl;
            if(q.empty())
                break;
            q.push(INT_MIN);
            
            continue;
        }
        cout<<node<<" ";
        for (int i = 0; i < n; i++)
        {
            if(node == i)
            {
                continue;
            }
            if(edges[node][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
        // q.push(INT_MIN);
        
    }
    delete [] visited;
}
int32_t main(){
    int n, e;
    cin >> n >> e;
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
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    q.push(0);
    visited[0] = true;
    bfs(edges, q, visited, n);
    cout<<endl;
    bfsIterative(edges, 0, n);
    delete [] visited;
    return 0;
}