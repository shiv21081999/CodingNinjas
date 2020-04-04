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

void update(int *tree, int *lazy, int start, int end, int l, int r, int value, int node)
{
    if(lazy[node] != 0)
    {
        tree[node] += (lazy[node]*(end - start + 1));
        if(start != end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > r || l > end)
    {
        return;
    }
    
    if(l <= start && end <= r)
    {
        tree[node] += (value*(end - start + 1));
        if(start != end)
        {
            lazy[2*node] += value;
            lazy[2*node+1] += value;
        }
        return;
    }
    int mid = (start + end)/2;
    update(tree, lazy, start, mid, l, r, value, 2*node);
    update(tree, lazy, mid+1, end, l, r, value, 2*node+1);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int *tree, int *lazy, int start, int end ,int l, int r, int node)
{
    if(lazy[node]!=0)
    {
        tree[node] += (lazy[node]*(end - start + 1));
        if(start != end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > r || l > end)
    {
        return 0;
    }
    
    if(l <= start && end <= r)
    {
        
        return tree[node];
    }
    int mid = (start + end)/2;
    int ans1 = query(tree, lazy, start, mid, l, r, 2*node);
    int ans2 = query(tree, lazy, mid+1, end, l, r, 2*node+1);
    return ans1+ans2;
}

int32_t main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int q;
        cin>>q;
        int *tree = new int[4*n];
        int *lazy = new int[4*n];
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        while(q--)
        {
            int m,l,r,x;
            cin>>m;
            if(m==0)
            {
                cin>>l>>r>>x;
                update(tree, lazy, 0, n-1, l-1, r-1, x, 1);
            }
            else
            {
                cin>>l>>r;
                int ans = query(tree, lazy, 0, n-1, l-1, r-1, 1);
                cout<<ans<<endl;
            }
        }
        // delete [] tree;
        // delete [] lazy;
    }
    
    return 0;
}