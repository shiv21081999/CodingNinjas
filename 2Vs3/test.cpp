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
int twomods[100001];
void build(string str, int *tree, int start, int end, int node)
{
    if(start == end)
    {
        if(str[start] == '1')
            tree[node] = 1;
        else
            tree[node] = 0;
        return;
    }
    int mid = (start + end)/2;
    build(str, tree, start, mid, 2*node);
    build(str, tree, mid+1, end, 2*node+1);
    int mul = twomods[end - mid];
    tree[node] = ((tree[2*node]*mul)%3 + tree[2*node+1])%3;
}

void update(string str , int *tree, int start, int end, int index, int node)
{
    if(start == end)
    {
        str[start] = '1';
        tree[node] = 1;
        return;
    }
    int mid = (start + end)/2;
    if(index<= mid)
        update(str, tree, start, mid, index, 2*node);
    else
        update(str, tree, mid+1, end, index, 2*node+1);
    int mul = twomods[end - mid];
    tree[node] = ((tree[2*node]*mul)%3 + tree[2*node+1])%3;
}

int query(int *tree, int start, int end, int l, int r, int node)
{
    if(l>end || r<start)
    {
        return 0;
    }
    if(l <= start && end <= r)
    {
        int mul = twomods[r-end];
        return (mul * tree[node]);
    }
    int mid = (start + end)/2;
    int left = query(tree, start, mid, l, r, 2*node);
    int right = query(tree, mid+1, end, l, r, 2*node+1);
    return (left + right)%3;
}

int32_t main(){
    int n,q;
    string str;
    twomods[0] = 1;
    for (int  i = 1; i < 100001; i++)
    {
        twomods[i] = (twomods[i-1]*2)%3;
    }
    // for (int i = 0; i < 100001; i++)
    // {
    //     cout<<twomods[i]<<" ";
    // }
    // cout<<endl;
    cin>>n;
    cin>>str;
    // cout<<"length : "<<str.length()<<endl;
    int *tree = new int[4*n];
    build(str, tree, 0, n-1, 1);
    // for (int i = 0; i < 4*n; i++)
    // {
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;
    cin>>q;
    // cout<<"Q : "<<q<<endl;
    while(q--)
    {
        int m,l,r;
        cin>>m;
        if(m==0)
        {
            cin>>l>>r;
            int ans = query(tree, 0, n-1, l, r, 1);
            cout<<ans<<endl;
        }
        else
        {
            cin>>l;
            if(str[l] != '1')
                update(str, tree, 0, n-1, l, 1);
            // for (int i = 0; i < 4*n; i++)
            // {
            //     cout<<tree[i]<<" ";
            // }
            // cout<<endl;
        }
    }
    delete [] tree;
    return 0;
}