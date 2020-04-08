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

struct Edge{
    int start;
    int end;
    int weight;
};

int root(int *parent, int node)
{
    if(parent[node] == node)
        return node;
    parent[node] = parent[parent[node]];
    return root(parent, parent[node]);
}

void union_rank(int *parent, int *rank, int a, int b)
{
    int roota = root(parent, a);
    int rootb = root(parent, b);
    if(rank[roota] > rank[rootb])
    {
        parent[rootb] = parent[roota];
    }
    else if(rank[rootb] > rank[roota])
    {
        parent[roota] = parent[rootb];
    }
    else
    {
        parent[roota] = parent[rootb];
        rank[rootb]++;
    }
    
}

int getParent(int *parent, int node)
{
    if(parent[node] == node)
        return node;
    return getParent(parent , parent[node]); 
}

int32_t main(){
    int n , e;
    cin>>n>>e;
    Edge *edges = new Edge[e];

    for (int i = 0; i < e; i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        edges[i].start = f;
        edges[i].end = s;
        edges[i].weight = w;
    }
    sort(edges, edges + e, [&](Edge a, Edge b){
        return a.weight < b.weight;
    });

    int *parent = new int[n];
    int *rank = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    // for (int i = 0; i < e; i++)
    // {
    //     cout<<edges[i].start<<" "<<edges[i].end<<" "<<edges[i].weight<<endl;
    // }
    // cout<<endl;
    vector<Edge> ans;
    int count = 0;
    for (int i = 0; i < e; i++)
    {
        int p1 = root(parent, edges[i].start);
        int p2 = root(parent, edges[i].end);
        if(p1 != p2)
        {
            count++;
            ans.pb(edges[i]);
            union_rank(parent, rank, p1, p2);
            if(count == n-1)
                break;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<min(ans[i].start, ans[i].end)<<" "<<max(ans[i].end, ans[i].start)<<" "<<ans[i].weight<<endl;
    }
    delete [] edges;
    delete [] parent;
    delete [] rank;
    return 0;
}