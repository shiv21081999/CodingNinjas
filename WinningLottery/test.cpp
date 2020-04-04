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
    int sum , digits;
    string ans = "";
    cin>>sum>>digits;
    sum--;
    int count = 0;
    for (int i = 1; i < digits; i++)
    {
        count++;
        if(sum - 9 >= 0)
        {
            ans = to_string(9)+ans;
            sum-= 9;
        }
        else{
            ans = to_string(sum)+ans;
            sum = 0;
        }
    }
    // cout<<count<<endl;
    ans = to_string(sum+1)+ans;
    cout<<ans<<endl;
    return 0;
}