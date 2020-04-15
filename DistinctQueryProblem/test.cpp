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
struct node{
	int l;
	int r;
	int i;
};

void update(int index , int val, int *BIT, int n)
{
	for(; index <= n; index += (index&(-index)))
	{
		BIT[index]+= val;
	}
}

int query(int index,int *BIT)
{
	int count = 0;
	for(; index > 0 ; index-= (index&(-index)))
	{
		count += BIT[index];
	}
	return count;
}

int32_t main(){
	int n;
	cin>>n;
	int *arr = new int[n+1];
	for (int i = 1; i <= n; i++)
	{
		cin>>arr[i];
	}
	int q;
	cin>>q;
	node *queries = new node[q];
	for (int i = 0; i < q; i++)
	{
		int f,s;
		cin>>f>>s;
		queries[i].l = f;
		queries[i].r = s;
		queries[i].i = i;
	}
	sort(queries, queries + q, [&](node a, node b){
		return a.r<b.r;
	});
	int *BIT = new int[n+1];
	int *ans = new int[q];
	int total = 0;
	int index = 0;
	unordered_map<int,int> map;
	for (int i = 1; i <= n; i++)
	{
		if(map.find(arr[i])!= map.end())
		{
			update(map[arr[i]], -1, BIT, n);
		}
		else
		{
			total++;
		}
		update(i, 1, BIT, n);
		map[arr[i]] = i;
		while(index < q && queries[index].r == i)
		{
			ans[queries[index].i] = total - query(queries[index].l-1, BIT);
			index++;
		}
	}
	for (int i = 0; i < q; i++)
	{
		cout<<ans[i]<<endl;
	}
	delete [] BIT;
	delete [] arr;
	delete [] ans;
	delete [] queries;
	
	return 0;
}