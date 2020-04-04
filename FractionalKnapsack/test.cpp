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
    int time;
    int cost;
    int speed;
};
int32_t main(){
    int n,d;
    cin>>n>>d;
    values *arr = new values[n];
    for(int i = 0 ; i < n ; i++){
        int t,x,y;
        cin>>t>>x>>y;
        values temp ;
        temp.time = t;
        temp.cost = x;
        temp.speed = y;
        arr[i] = temp;
    }
    sort(arr, arr+n, [&](values a, values b){
        if(a.time == b.time)
        {
            if(a.speed == b.speed)
                return a.cost<b.cost;
            return a.speed>b.speed;
        }
        return a.time<b.time;
    });
    int cost = 0;
    int lastselected = 0;
    int speed = 0;
    int workleft = d;
    for(int i = 0 ; i < n ; i++){
        if(arr[i].speed > speed)
        {
            speed = arr[i].speed;
            lastselected = i;
            cost+= arr[i].cost;
        }
        if(i == n)
        {
            workleft -= speed;
        }
        else
            workleft-= ((arr[i+1].time - arr[i].time)*speed);
        if(workleft <= 0)
            break;
    }
    cout<<cost<<endl;
}