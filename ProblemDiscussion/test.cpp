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
int32_t main(){
    int n, k;
    cin>>n>>k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int ans = arr[n-1] - arr[0];
    int small = arr[0]+k;
    int big = arr[n-1]-k;
    for (int i = 1; i < n; i++)
    {
        int subtract = arr[i] - k;
        int add = arr[i] + k;
        if(subtract >= small || add <=big)
            continue;
        if(big - subtract <= add - small)
            small = subtract;
        else
            big = add;
    }
    cout<<min(big - small, ans);
    
    return 0;
}