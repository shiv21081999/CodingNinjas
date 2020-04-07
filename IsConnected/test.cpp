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

void DFS(int **edges , int n, int s, bool *visited){
    visited[s] = true;

    for (int i = 0; i < n; i++)
    {
        if(i == s)
            continue;
        if(edges[s][i] == 1 && !visited[i])
        {
            DFS(edges, n, i, visited);
        }
    }
    
}

int32_t main(){
    int n,e;
    cin>>n>>e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++){
        edges[i] = new int[n];
    }
    int start = 0;
    for (int i = 0; i < e; i++){
        int f,s;
        cin>>f>>s;
        if(i==0)
            start = f;
        
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // cout<<"reached";
    DFS(edges, n, start, visited);

    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
    return 0;
}