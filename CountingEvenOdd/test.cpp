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
    int even;
    int odd;
};

void build(int *arr, Node *tree, int start, int end, int node)
{
    if(start == end)
    {
        if(arr[start]%2==0)
            tree[node].even = 1;
        else
            tree[node].odd = 1;
        return;
    }
    int mid = (start + end)/2;
    build(arr, tree, start, mid, 2*node);
    build(arr, tree, mid+1, end, 2*node+1);
    tree[node].even = tree[2*node].even + tree[2*node+1].even;
    tree[node].odd = tree[2*node].odd + tree[2*node+1].odd;
}

void update(int *arr, Node *tree, int start, int end , int index ,int value, int node)
{
    if(start == end)
    {
        if(arr[index]%2==0)
        {
            if(value%2!=0)
            {
                tree[node].even--;
                tree[node].odd++;
            }
        }
        else
        {
            if(value%2==0)
            {
                tree[node].even++;
                tree[node].odd--;
            }
        }
        arr[index] = value;
        return;
    }
    int mid = (start + end)/2;
    if(index > mid)
        update(arr, tree, mid+1, end, index, value, 2*node+1);
    else
        update(arr, tree, start, mid, index, value, 2*node);
    tree[node].even = tree[2*node].even + tree[2*node+1].even;
    tree[node].odd = tree[2*node].odd + tree[2*node+1].odd;
}

int query(Node *tree, int start, int end, int l, int r, int value, int node)
{
    if(r<start || l > end)
        return 0;

    if(l<=start && end <=r)
    {
        if(value== 1)
            return tree[node].even;
        else
            return tree[node].odd;
    }
    int mid = (start + end)/2;
    int ans1 = query(tree, start, mid, l, r, value, 2*node);
    int ans2 = query(tree, mid+1, end, l, r, value, 2*node+1);
    return ans1+ans2;
}

int32_t main(){
    int n,q;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    Node *tree = new Node[4*n];
    build(arr, tree, 0, n-1, 1);
    // for (int i = 0; i < 4*n; i++)
    // {
    //     cout<<tree[i].even<<","<<tree[i].odd<<" ";
    // }
    // cout<<endl;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int m,x,y;
        cin>>m>>x>>y;
        if(m==0)
        {
            update(arr, tree, 0, n-1, x-1,y, 1);
            // for (int i = 0; i < 4*n; i++)
            // {
            //     cout<<tree[i].even<<","<<tree[i].odd<<" ";
            // }
            // cout<<endl;
        }
        else{
            cout<<query(tree, 0, n-1, x-1, y-1, m, 1)<<endl;
        }
    }
    
    return 0;
}