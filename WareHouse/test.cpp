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
#define MULTIPLY(a,b) a*b;
int32_t main(){
    int n;
    cin>>n;
    int *x = new int[n];
    int *y = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>y[i];
    }
    sort(y, y+n);
    int max = INT_MIN;
    for (int i = 0; i < n-1; i++)
    {
        int diff = y[i+1]-y[i];
        if(diff > max)
            max = diff;
    }
    cout<<max-1<<endl;
    return 0;
}