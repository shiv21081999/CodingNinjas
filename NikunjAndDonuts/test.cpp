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
    int n ;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,[&](int a , int b){
        return a>b;
    });
    int ans = 0;
    int j = 0;
    for(int i = 0 ; i < n ; i++){
        int mul = pow(2,j);
        ans += (mul*arr[i]);
        j++;
    }
    cout<<ans<<endl;
}