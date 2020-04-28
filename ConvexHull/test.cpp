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

class Point{
    public:
        double x;
        double y;
};

int32_t main(){
    int n;
    cin>>n;
    Point *arr = new Point[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i].x;
    }
    
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i].y;
    }
    sort(arr, arr + n, [&](Point a, Point b){
        return a.x<b.x;
    });
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i].x<<" "<<arr[i].y<<endl;
    // }
    
    int p,q,r;
    p = 0;
    int i = 1;
    vector<Point> ans;
    do{
        ans.pb(arr[p]);
        q = (p+1)%n;
        for (int j = 0; j < n; j++)
        {
            r = j;
            double x1 = arr[q].x - arr[p].x;
            double y1 = arr[q].y - arr[p].y;
            double x2 = arr[r].x - arr[q].x;
            double y2 = arr[r].y - arr[q].y;
            double cross = (x1*y2 - y1*x2);
            if(cross < 0)
            {
                q = r;
                i = j+1;
            }
        }
        p = q;
        
    }while(p!=0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i].x<<" "<<ans[i].y<<endl;
    }
    
    return 0;
}