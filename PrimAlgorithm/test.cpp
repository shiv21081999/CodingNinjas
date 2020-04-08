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

struct node{
    int index;
    int weight;
};
class comp{
    public:
        int operator() (const node &a, const node &b)
        {
            return b.weight < a.weight;
        }
};


void getMST(vector<vector<node>> adjlist, bool *visited, int n)
{
    int *parent = new int[n];
    parent[0] = -1;
    priority_queue<node,vector<node>,comp> pq;
    int *weight = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        weight[i] = LLONG_MAX;
    }
    node temp;
    temp.index = 0;
    temp.weight = 0;
    pq.push(temp); 
    pq.
    while(!pq.empty())
    {
        // int minVertex = getMinVertex(visited, pq);
        int minVertex = pq.top().index;
        pq.pop();
        visited[minVertex] = true;
        for (int j = 0; j < adjlist[minVertex].size(); j++)
        {
            node x = adjlist[minVertex][j];
            if(!visited[x.index])
            {
                if(weight[x.index] > x.weight)
                {
                    weight[x.index] = x.weight;
                    parent[x.index] = minVertex;
                    pq.push(x);
                }
            }
        }
        
    }
    for (int i = 1; i < n; i++)
    {
        if(parent[i] < i)
        {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        
    }
    
    delete [] parent;
    delete [] weight;
}

int32_t main(){
    int n, e;
    cin>>n>>e;
    vector<vector<node>> adjlist;
    // adjlist.resize(n);
    for (int i = 0; i < n; i++)
    {
        vector<node>temp;
        adjlist.pb(temp);
    }
    
    for (int i = 0; i < e; i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        node temp;
        temp.index = s;
        temp.weight = w;
        adjlist[f].pb(temp);
        temp.index = f;
        temp.weight = w;
        adjlist[s].pb(temp);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<i<<" ";
    //     for (int j = 0; j < adjlist[i].size(); j++)
    //     {
    //         cout<<"("<<adjlist[i][j].index<<","<<adjlist[i][j].weight<<")"<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    getMST(adjlist, visited, n);
    delete [] visited;
    return 0;
}