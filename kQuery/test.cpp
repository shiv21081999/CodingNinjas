/*
	in this code scanf and printf  is mandatoru to use.
*/
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
int BIT[30001];
struct Query{
	int l;
	int r;
	int val;
	int i;
};
struct Data{
	int data;
	int i;
};

void update(int i)
{
	for(; i<=30000; i+=(i&(-i)))
	{
		BIT[i]++;
	}
}

int query(int i)
{
	int count =0;
	while(i)
	{
		count+= BIT[i];
		i-=(i&(-i));
	}
	return count;
}

int32_t main(){
	int n;
	// cin>>n;
	scanf("%lli",&n);
	Data *arr = new Data[n+1];
	for (int i = 1; i <= n; i++)
	{
		// cin>>arr[i].data;
		scanf("%lli",&arr[i].data);
		arr[i].i = i;
	}
	int q;
	cin>>q;
	sort(arr+1, arr + n+1, [&](Data a, Data b){
		return a.data>b.data;
	});
	Query *event = new Query[q];
	for (int i = 0; i < q; i++)
	{
		// cin>>event[i].l>>event[i].r>>event[i].val;
		scanf("%lli%lli%lli",&event[i].l,&event[i].r,&event[i].val);
		event[i].i = i;
	}
	sort(event, event + q, [&](Query a, Query b){
		return a.val > b.val;
	});
	int pos = 1;
	int *ans = new int[q];
	for (int i = 0; i < q; i++)
	{
		while(pos<=n && arr[pos].data > event[i].val)
		{
			update(arr[pos].i);
			pos++;
		}
		ans[event[i].i] = query(event[i].r) - query(event[i].l-1);
	}
	for (int i = 0; i < q; i++)
	{
		// cout<<ans[i]<<endl;
		printf("%lli\n",ans[i]);
	}
	
	delete [] ans;
	delete [] arr;
	delete [] event;
	return 0;
}