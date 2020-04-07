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

bool BFS(int **edges, int n ,int s, int e)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    map<int, int> track;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    bool flag = false;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if(i == node)
                continue;
            if(edges[node][i] == 1 && !visited[i])
            {
                track[i] = node;
                q.push(i);
                visited[i] = true;
                if(i == e)
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            break;
        
    }
    if(flag)
    {
        cout<<e<<" ";
        while(true)
        {
            int start = track[e];
            cout<<start<<" ";
            e = start;
            if(start == s)
                break;
        }
        return true;
    }
    return false;
}

int32_t main(){
    int n, e;
    cin>>n>>e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++){
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
        
    }
    for (int i = 0; i < e; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    
    int start, end;
    cin>>start>>end;
    bool ans = BFS(edges, n, start, end);
    return 0;
}