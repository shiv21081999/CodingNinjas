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

vector<int> path;

bool DFS(int **edges, int n, int start, int end , bool *visited)
{
    if(start == end)
        return true;
    visited[start] = true;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if(i==start)
            continue;
        if(edges[start][i] == 1 && !visited[i])
        {
            ans = DFS(edges, n, i, end, visited);
            if(ans == true)
            {
                path.pb(i);
                return true;
            }
        }
    }
    return ans;
}

int32_t main(){
    int n , e, start, end;
    cin>>n>>e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
    }
    for (int i = 0; i < e; i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cin>>start>>end;
    bool *visited = new bool[n];
    if(DFS(edges, n, start, end, visited))
    {
        path.pb(start);
        for (int i = 0; i < path.size(); i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}