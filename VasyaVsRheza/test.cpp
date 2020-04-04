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
struct Node{
    int a,b,index;
};

Node compare(Node a, Node b)
{
    if(a.a == b.a)
    {
        if(a.b == b.b)
        {
            if(a.index < b.index)
                return a;
            return b;
        }
        if(a.b<b.b)
            return a;
        return b;
    }
    if(a.a < b.a)
        return b;
    return a;
}

void build(int *a, int *b, Node *tree, int start, int end, int node)
{
    if(start == end)
    {
        tree[node].a = a[start];
        tree[node].b = b[start];
        tree[node].index = start;
        return;
    }
    int mid = (start + end)/2;
    build(a, b, tree, start, mid, 2*node);
    build(a, b, tree, mid+1, end, 2*node+1);
    tree[node] = compare(tree[2*node], tree[2*node+1]);
}

Node query(Node *tree, int start, int end , int l, int r, int node)
{
    if(r<start || l>end)
    {
        Node temp;
        temp.a = INT_MIN;
        temp.b = INT_MAX;
        temp.index = INT_MAX;
        return temp;
    }
    if(l <= start && end <= r)
    {
        return tree[node];
    }
    int mid = (start + end)/2;
    Node left = query(tree, start, mid, l, r, 2*node);
    Node right = query(tree, mid+1 , end, l, r, 2*node+1);
    return compare(left, right);
}

int32_t main(){
    int n,q;
    cin>>n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    Node *tree = new Node[4*n];
    build(a, b, tree, 0, n-1, 1);
    // for (int i = 0; i < 4*n; i++)
    // {
    //     cout<<tree[i].a<<","<<tree[i].b<<","<<tree[i].index<<"  ";
    // }
    // cout<<endl;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin>>l>>r;
        Node ans = query(tree, 0, n-1, l-1, r-1, 1);
        cout<<ans.index+1<<endl;
    }
    
    return 0;
}