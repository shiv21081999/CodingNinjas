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
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n, greater<int>());
    int maxPeri = 0, a,b,c;
    for (int i = 0; i < n-2; i++)
    {
        if(arr[i]+arr[i+1]+arr[i+2] > maxPeri)
        {
            maxPeri = arr[i]+arr[i+1]+arr[i+2];
            a = arr[i];
            b = arr[i+1];
            c = arr[i+2];
        }
    }
    cout<<c<<" "<<b<<" "<<a<<endl;
    return 0;
}