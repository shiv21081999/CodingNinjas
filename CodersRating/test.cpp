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
	int x;
	int y;
	int index;
};

int query(int y, int *BIT)
{
	int count = 0;
	for(;  y > 0  ; y-= (y&(-y)) ){
		count+= BIT[y];
	}
	return count;
}

void update(int y, int *BIT)
{
	for( ; y<=100000; y += (y&(-y)))
		BIT[y]++;
}

int32_t main(){
	int n;
	cin>>n;
	node* arr = new node[n];
	for (int i = 0; i < n; i++)
	{
		int f,s;
		cin>>f>>s;
		arr[i].x = f;
		arr[i].y = s;
		arr[i].index = i;
	}
	sort(arr, arr + n, [&](node a, node b){
		if(a.x == b.x)
			return a.y<b.y;
		return a.x<b.x;
	});
	int *BIT = new int[100001];
	int *ans = new int[n];
	for (int i = 0; i < n; )
	{
		int endIndex = i;
		while(endIndex < n && arr[i].x == arr[endIndex].x && arr[i].y == arr[endIndex].y)
			endIndex++;
		for (int j = i; j < endIndex; j++)
		{
			ans[arr[j].index] = query(arr[j].y, BIT);
			// cout<<"here"<<endl;
		}
		for (int j = i; j < endIndex; j++)
		{
			update(arr[j].y,BIT);
		}
		i = endIndex;
	}

	for (int i = 0; i < n; i++)
	{
		cout<<ans[i]<<endl;
	}
	delete [] arr;
	delete [] ans;
	delete [] BIT;
	return 0;
}