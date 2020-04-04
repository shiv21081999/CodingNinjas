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
    int sum=INT_MIN;
    int maxSum=INT_MIN;
    int suff=INT_MIN;
    int pref=INT_MIN;
};

void build(int *arr, values *tree, int start, int end, int node)
{
    if(start == end)
    {
        tree[node].sum = tree[node].suff = tree[node].pref = tree[node].maxSum = arr[start];
        return;
    }
    int mid = (start + end)/2;
    build(arr, tree, start, mid, 2*node);
    build(arr, tree, mid+1, end, 2*node+1);
    values left = tree[2*node];
    values right = tree[2*node+1];
    int sum = left.sum + right.sum;
    int maxSum = max(max(left.maxSum, right.maxSum),max(max(left.sum+right.pref,right.sum+left.suff),left.suff+right.pref));
    tree[node].sum = sum;
    tree[node].maxSum = maxSum;
    tree[node].pref = max(left.pref,left.sum + right.pref);
    tree[node].suff = max(right.suff,left.suff + right.sum);
}
values query(values *tree, int start , int end , int l, int r, int node)
{
    if(l>end || r<start)
    {
        values temp;
        return temp;
    }
    if(l<=start && end<=r)
    {
        return tree[node];
    }
    int mid = (start + end )/2;
    values left = query(tree, start, mid, l, r, 2*node);
    values right = query(tree, mid+1, end, l, r, 2*node+1);
    values temp;
    int sum = left.sum + right.sum;
    int maxSum = max(max(left.maxSum, right.maxSum),max(max(left.sum+right.pref,right.sum+left.suff),left.suff+right.pref));
    temp.sum = sum;
    temp.maxSum = maxSum;
    temp.pref = max(left.pref,left.sum + right.pref);
    temp.suff = max(right.suff,left.suff + right.sum);
    return temp;
}
int32_t main(){
    int n,q;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    values *tree = new values[4*n];
    build(arr, tree, 0, n-1, 1);
    // for (int i = 0; i < 4*n; i++)
    // {
    //     cout<<tree[i].sum<<" "<<tree[i].maxSum<<" "<<tree[i].suff<<" "<<tree[i].pref<<endl;
    // }
    // cout<<endl;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int l,r;
        cin>>l;
        cin>>r;
        values ans = query(tree, 0,n-1,l-1,r-1,1);
        cout<<max(max(ans.maxSum,ans.sum),max(ans.suff, ans.pref))<<endl;
    }
    
    delete [] arr;
    delete [] tree;
    return 0;
}