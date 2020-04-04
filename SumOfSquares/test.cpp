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
struct Tree{
    int sum;
    int squaresum;
};
struct Lazy{
    int value;
    int mode = 2;
};

void buildTree(int *arr, Tree *tree, int start, int end, int node)
{
    if(start == end)
    {
        tree[node].squaresum = arr[start]*arr[start];
        tree[node].sum = arr[start];
        return;
    }
    int mid = (start + end)/2;
    buildTree(arr, tree, start, mid, 2*node);
    buildTree(arr, tree, mid+1, end, 2*node+1);
    tree[node].squaresum = tree[2*node].squaresum + tree[2*node+1].squaresum;
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}

void update(Tree *tree, Lazy *lazy, int start , int end, int l, int r, int value,int mode, int node)
{
    if(r<start || l >end)
        return;
    if(l<=start && end<=r)
    {
        if(lazy[node].mode != 2)
        {
            if(lazy[node].mode == 1)
            {
                tree[node].squaresum += (((end-start+1)*lazy[node].value*lazy[node].value) +(2*lazy[node].value*tree[node].sum));
                tree[node].sum += (end-start+1)*lazy[node].value;
                if(start != end)
                {
                    lazy[2*node+1].mode = lazy[node].mode;
                    lazy[2*node+1].value = lazy[node].value;
                    lazy[2*node].mode = lazy[node].mode;
                    lazy[2*node].value = lazy[node].value;
                }
                lazy[node].value = 0;
                lazy[node].mode = 2;
            }
            else
            {
                tree[node].squaresum = (end-start+1)*lazy[node].value*lazy[node].value;
                tree[node].sum = (end-start+1)*lazy[node].value;
                if(start != end)
                {
                    lazy[2*node+1].mode = lazy[node].mode;
                    lazy[2*node+1].value = lazy[node].value;
                    lazy[2*node].mode = lazy[node].mode;
                    lazy[2*node].value = lazy[node].value;
                }
                lazy[node].value = 0;
                lazy[node].mode = 2;
            }
        }
        if(mode == 1)
        {
            tree[node].squaresum += (((end-start+1)*value*value) +(2*value*tree[node].sum));
            tree[node].sum += (end-start+1)*value;
            if(start!=end)
            {
                lazy[2*node].value = value;
                lazy[2*node].mode = mode;
                lazy[2*node+1].value = value;
                lazy[2*node+1].mode = mode;
            }
        }
        else if(mode == 0)
        {
            tree[node].squaresum = (end-start+1)*value*value;
            tree[node].sum = (end-start+1)*value;
            if(start != end)
            {
                lazy[2*node].value = value;
                lazy[2*node].mode = mode;
                lazy[2*node+1].value = value;
                lazy[2*node+1].mode = mode;
            }
        }
        return;
    }
    int mid = (start + end)/2;
    update(tree,lazy,start,mid,l,r,value , mode,2*node);
    update(tree,lazy,mid+1,end,l,r,value,mode,2*node+1);
    tree[node].squaresum = tree[2*node].squaresum + tree[2*node+1].squaresum;
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}

int query(Tree *tree, Lazy * lazy , int start, int end, int l, int r, int node)
{
    if(r<start || end <l)
    {
        return 0;
    }
    if(l<=start && end<=r)
    {
        // if(lazy[node].mode != 2)
        // {
        //     if(lazy[node].mode == 1)
        //     {
        //         tree[node].squaresum += (((end-start+1)*lazy[node].value*lazy[node].value) +(2*lazy[node].value*tree[node].sum));
        //         tree[node].sum += (end-start+1)*lazy[node].value;
        //         if(start != end)
        //         {
        //             lazy[2*node+1].mode = lazy[node].mode;
        //             lazy[2*node+1].value += lazy[node].value;
        //             lazy[2*node].mode = lazy[node].mode;
        //             lazy[2*node].value += lazy[node].value;
        //         }
        //         lazy[node].value = 0;
        //         lazy[node].mode = 2;
        //     }
        //     else
        //     {
        //         tree[node].squaresum = (end-start+1)*lazy[node].value*lazy[node].value;
        //         tree[node].sum = (end-start+1)*lazy[node].value;
        //         if(start != end)
        //         {
        //             lazy[2*node+1].mode = lazy[node].mode;
        //             lazy[2*node+1].value = lazy[node].value;
        //             lazy[2*node].mode = lazy[node].mode;
        //             lazy[2*node].value = lazy[node].value;
        //         }
        //         lazy[node].value = 0;
        //         lazy[node].mode = 2;
        //     }
        // }
        return tree[node].squaresum;
    }
    int mid = (start + end)/2;
    int left = query(tree, lazy, start, mid, l, r, 2*node);
    int right = query(tree, lazy, mid+1, end, l, r, 2*node+1);
    return left + right;
}

int32_t main(){
    int t;
    cin>>t;
    int loop = 1;
    while (t--)
    {
        cout<<"Case "<<loop++<<":"<<endl;
        int n,q;
        cin>>n>>q;
        int *arr = new int[n];
        for (int  i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        Tree *tree = new Tree[4*n];
        Lazy *lazy = new Lazy[4*n];
        buildTree(arr, tree, 0, n-1, 1);
        // for (int i = 0; i < 4*n; i++)
        // {
        //     cout<<tree[i].squaresum<<","<<tree[i].sum<<" ";
        // }
        // cout<<endl;
        // for (int i = 0; i < 4*n; i++)
        // {
        //     cout<<lazy[i].mode<<","<<lazy[i].value<<" ";
        // }
        // cout<<endl;
        for (int i = 0; i < q; i++)
        {
            int mode,l,r,x;
            cin>>mode;
            if(mode == 2)
            {
                cin>>l>>r;
                cout<<query(tree, lazy, 0, n-1, l-1, r-1, 1)<<endl;
            }
            else
            {
                cin>>l>>r>>x;
                update(tree, lazy, 0, n-1, l-1, r-1,x, mode,1);
            }
        }
        delete [] tree;
        delete [] arr;
        delete [] lazy;
        
    }
    
    return 0;
}