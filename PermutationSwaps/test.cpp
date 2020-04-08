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

int root(int *parent , int node)
{
    if(node == parent[node])
        return node;
    parent[node] = parent[parent[node]];
    return root(parent, parent[node]);
}

void better_union(int *parent, int *rank, int a, int b)
{
    int roota = root(parent, a);
    int rootb = root(parent, b);
    if(rank[roota] > rank[rootb])
    {
        parent[rootb] = parent[roota];
    }
    else if(rank[rootb] > rank[roota]){
        parent[roota] = parent[rootb];
    }
    else
    {
        parent[roota] = parent[rootb];
        rank[rootb]++;
    }
    
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int *parent = new int[n];
        int *rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        
        int *p = new int[n];
        int *q = new int[n];
        map<int, int> pi;
        map<int,int> qi;
        for (int i = 0; i < n; i++)
        {
            cin>>p[i];
            pi[p[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin>>q[i];
            qi[q[i]] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int f,s;
            cin>>f>>s;
            int rootf = root(parent, f-1);
            int roots = root(parent, s-1);
            if(rootf != roots)
                better_union(parent, rank, f-1, s-1);
        }
        bool flag = true;
        for(auto x : pi)
        {
            int rootp = root(parent, x.S);
            int rootq = root(parent, qi[x.F]);
            if(rootp != rootq)
            {
                flag = false;
            }
        }   
        if(flag)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        delete [] parent;
        delete [] rank;
        delete [] p;
        delete [] q;
    }
    return 0;
}