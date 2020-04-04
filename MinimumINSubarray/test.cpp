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

void buildTree(int *arr, int *tree, int start , int end, int treeNode){
    if(start==end)
    {
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start + end)/2;
    buildTree(arr, tree, start, mid,2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
}

void update(int *tree, int start, int end,int treeNode, int index , int value)
{
    if(start == end)
    {
        tree[treeNode] = value;
        return;
    }
    int mid = (start + end)/2;
    if(index <= mid)
        update(tree, start , mid , 2*treeNode, index, value);
    else
        update(tree, mid+1,end, 2*treeNode+1, index, value);
    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

int query(int *tree, int start, int end ,int l , int r, int treeNode)
{
    // cout<<start<<" "<<end<<" "<<l<<" "<<r<<endl;
    if(l>end || r<start)
        return INT_MAX;
    if(l <= start && end <= r)
        return tree[treeNode];
    int mid = (start + end)/2;
    int ans1 = query(tree, start, mid, l, r, 2*treeNode);
    int ans2 = query(tree, mid+1, end, l, r, 2*treeNode + 1);
    return min(ans1, ans2);
}

int32_t main(){
    int n,q;
    cin>>n>>q;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int *tree = new int[4*n+1];
    buildTree(arr, tree, 0, n-1,1);
    // cout<<"build complete"<<endl;
    // for (int i = 0; i < 4*n+1; i++)
    // {
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;
    for (int i = 0; i < q; i++)
    {
        char x;
        int l,r;
        cin>>x;
        cin>>l>>r;
        // cout<<l<<" "<<r<<endl;
        if(x == 'q')
        {
            int ans = query(tree,0,n-1,l-1,r-1,1);
            cout<<ans<<endl;
        }
        else
        {
            update(tree, 0, n-1, 1,l-1,r);
        }
        
    }
    
    return 0;
}