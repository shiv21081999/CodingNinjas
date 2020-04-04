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

void print(bool **edges, int n, int sv, bool *visited)
{
    cout<<sv<<" ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if(i==sv)
            continue;
        if(edges[sv][i] == true)
        {
            if(visited[i] == false)
            {
                print(edges, n, i, visited);
            }
        }
    }
    
}

int32_t main(){
    int n ,e;
    cin>>n;
    cin>>e;
    bool **edges = new bool*[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = false;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin>>f>>s;
        edges[f][s] = true;
        edges[s][f] = true;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<edges[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    print(edges, n, 0, visited);
    return 0;
}