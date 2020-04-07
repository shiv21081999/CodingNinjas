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
bool DFS(int** edges, int n ,int s, int e, bool *visited)
{
    if(s==e)
    {
        return true;
    }
    bool ans = false;
    visited[s] = true;
    for (int i = 0; i < n; i++)
    {
        if(i == s)
            continue;
        if(edges[s][i] == 1 && !i[visited])
        {
            ans = DFS(edges, n, i, e, visited);
            if(ans == true)
                return true;
        }
    }
    return ans;
    
}
int32_t main(){
    int n,e;
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
    int start,end;
    cin>>start>>end;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    
    if(DFS(edges, n, start, end, visited)){
        cout<<"true"<<endl;
        return 0;
    }
    cout<<"false"<<endl;
    return 0;
}