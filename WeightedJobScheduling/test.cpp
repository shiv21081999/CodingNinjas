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
    int start;
    int end;
    int profit;
};
int getMax(values *arr, int start , int end , int *profitarr, int index)
{
    int profit = 0;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(arr[mid].end <= arr[index].start)
        {
            if(profit < profitarr[mid])
            {
                profit = profitarr[mid];
            }
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }

    }
    return profit;
}
int32_t main(){
    int n;
    cin>>n;
    values *arr = new values[n];
    for(int i = 0 ; i < n ; i++){
        int s,e,p;
        cin>>s>>e>>p;
        values temp;
        temp.start = s;
        temp.end = e;
        temp.profit = p;
        arr[i] = temp;
    }
    sort(arr, arr+n, [&](values a, values b){
        if(a.end == b.end)
            return a.profit < b.profit;
        return a.end < b.end;
    });
    // for(int i = 0 ; i < n ; i++){
    //     cout<<arr[i].start<<" "<<arr[i].end<<" "<<arr[i].profit<<endl;
    // }
    int finalprofit = 0;
    int *profitarr = new int[n];
    profitarr[0] = arr[0].profit;
    for (int  i = 1; i < n; i++)
    {
        int profit = getMax(arr,0,i-1,profitarr, i);
        if(profit == 0)
            profitarr[i] = max(profitarr[i-1], arr[i].profit);
        else
        {
            profitarr[i] = max(profit + arr[i].profit, profitarr[i-1]);
        }
        
        // int maxprofit = 0;
        // profitarr[i] = max(profitarr[i-1] , arr[i].profit);
        // for (int j = i - 1; j >= 0; j--)
        // {
        //     if(arr[i].start >= arr[j].end)
        //     {
        //         if(profitarr[i]<profitarr[j]+arr[i].profit)
        //         {
        //             profitarr[i] = profitarr[j]+arr[i].profit;
        //         }
        //     }
        // }
        
    }

    for (int i = 0; i < n; i++)
    {
        // cout<<profitarr[i]<<" ";
        if(profitarr[i]>finalprofit)
            finalprofit = profitarr[i];
    }
    cout<<endl;
    cout<<finalprofit<<endl;
    return 0;
}