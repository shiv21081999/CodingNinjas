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
struct values{
    int max;
    int smax;
};
void buildTree(int *arr, values *tree, int start , int end,int treeNode){
    // cout<<start<<" "<<end<<endl;
    if(start == end)
    {
        tree[treeNode].max = arr[start];
        tree[treeNode].smax = INT_MIN;
        return;
    }
    int mid = start + (end - start)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    tree[treeNode].max = max(tree[2*treeNode].max,tree[2*treeNode+1].max);
    tree[treeNode].smax = min(max(tree[2*treeNode].max,tree[2*treeNode+1].smax),max(tree[2*treeNode].smax,tree[2*treeNode+1].max));
    
}

void update(int *arr, values *tree, int start, int end, int index, int value, int treeNode)
{
    
    if(start == end)
    {
        arr[index] = value;
        tree[treeNode].max = value;
        tree[treeNode].smax = INT_MIN;
        return;
    }
    int mid = (start + end)/2;
    if(index <= mid)
    {
        update(arr, tree, start , mid, index, value,2*treeNode);
    }
    else 
    {
        update(arr, tree, mid+1, end, index, value, 2*treeNode+1);
    }
    tree[treeNode].max = max(tree[2*treeNode].max,tree[2*treeNode+1].max);
    tree[treeNode].smax = min(max(tree[2*treeNode].max,tree[2*treeNode+1].smax),max(tree[2*treeNode].smax,tree[2*treeNode+1].max));
}

values query(values *tree, int start , int end, int l, int r, int treeNode)
{
    if(r<start || l>end)
    {
        values temp;
        temp.max = INT_MIN;
        temp.smax = INT_MIN;
        return temp;
    }
    if(r>=end && l<=start)
    {
        values temp;
        temp.max = tree[treeNode].max;
        temp.smax = tree[treeNode].smax;
        return temp;
    }
    int mid = (start + end)/2;
    values node1 = query(tree,start, mid,l,r,2*treeNode);
    values node2 = query(tree, mid+1, end,l,r,2*treeNode+1);
    int maximum = max(node1.max, node2.max);
    int smax = min(max(node1.max,node2.smax),max(node1.smax,node2.max));
    values node;
    node.max = maximum;
    node.smax = smax;
    return node;
}

int32_t main(){
    int n,q;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    values *tree = new values[4*n+1];
    // for (int i = 0; i <= 4*n; i++)
    // {
    //     cout<<tree[i].max<<","<<tree[i].smax<<" ";
    // }
    // cout<<endl;
    buildTree(arr, tree,0,n-1,1);
    cin>>q;
    // for (int i = 0; i <= 4*n; i++)
    // {
    //     cout<<tree[i].max<<","<<tree[i].smax<<" ";
    // }
    // cout<<endl;
    for (int i = 0; i < q; i++)
    {
        char x;
        int l,r;
        cin>>x;
        cin>>l>>r;
        if(x=='Q')
        {
            values ans = query(tree, 0, n-1, l-1, r-1, 1);
            cout<<ans.max + ans.smax<<endl;
        }
        else
        {
            update(arr, tree, 0, n-1, l-1, r, 1);
        }
        
    }
    delete [] arr;
    delete [] tree;
    return 0;
}