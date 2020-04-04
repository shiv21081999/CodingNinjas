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
    vector<P> arr;
    for(int i = 0 ; i < n ; i++){
        int x ,y;
        cin>>x>>y;
        P temp;
        temp.F = x;
        temp.S = y;
        arr.pb(temp);
    } 
    sort(arr.begin(),arr.end(), [&](P a, P b){
        return a.S<b.S;
    });
    int lastselected = 0;
    int ans = 1;
    // for(int i = 0 ; i < n ; i++){
    //     cout<<arr[i].F<<" "<<arr[i].S<<endl;
    // } 
    for(int i = 1 ; i < n ; i++){
        if(arr[i].F>=arr[lastselected].S)
        {
            ans++;
            lastselected = i;
        }
    }
    cout<<ans<<endl;
}