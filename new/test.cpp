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

void update(int *arr, int *tree, int *lazy, int start, int end, int l, int r, int value, int node)
{
    if(start > r || l > end)
    {
        return;
    }
    if(l <= start && end <= r)
    {
        tree[node] += value;
        if(start != end)
        {
            lazy[2*node] += value;
            lazy[2*node+1] += value;
        }
        return;
    }
    int mid = (start + end)/2;
    update(arr, tree, lazy, start, mid, l, r, value, 2*node);
    update(arr, tree, lazy, mid+1, end, l, r, value, node);
    
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
        int *arr = new int[n];
        int *temp = new int[4*n];
        int *lazy = new int[4*n];

    }
    
    return 0;
}