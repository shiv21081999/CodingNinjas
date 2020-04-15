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
	int v;
	int c;
};
node tmp[200010],A[200010];
int in[200010];
char c[200010];
int BIT[200011];

int binarySearch(int val, int n)
{
	int start = 1;
	int end = n;
	while(start <= end)
	{
		int mid = (start + end)/2;
		if(A[mid].v < val)
		{
			start = mid + 1;
		} 
		else
		{
			end = mid-1;
		}
		
	}
	return start;
}

void update(int y, int val)
{
	for(; y<=200010; y += (y&(-y)))
	{
		BIT[y]+=val;
	}
}

int query(int y)
{
	int count = 0;
	for(; y>0 ; y-= (y&(-y)))
	{
		count+=BIT[y];
	}
	return count;
}

int32_t main(){
	int n;
	cin>>n;
	int x=1;
	int m=1;
	for (int i = 1; i <= n; i++)
	{
		cin>>c[i]>>in[i];
		if(c[i] == 'I')
		{
			tmp[x++].v=in[i];
		}		
	}
	sort(tmp+1, tmp+x+1, [&](node a, node b){
		return a.v<b.v;
	});
	for (int i = 1; i < x+1; i++)
	{
		if(tmp[i-1].v != tmp[i].v)
		{
			A[m++] = tmp[i];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if(c[i] == 'I')
		{
			int y = binarySearch(in[i], m);
			A[y].c++;
			if(A[y].c == 1)
			{
				update(y, 1);
			}
		}
		else if(c[i] == 'D')
		{
			int y = binarySearch(in[i], m);
			if(A[y].c > 0 && A[y].v == in[i]){
				update(y, -1);
				A[y].c = 0;
			}
		}
		else if(c[i] == 'C')
		{
			int y = binarySearch(in[i], m);
			int ans = query(y-1);
			cout<<ans<<endl;
		}
		else
		{
			int s = 0;
			int e = m;
			while(s<=e)
			{
				int m = (s+e)/2;
				if(query(m)>=in[i])
					e = m-1;
				else
					s = m+1;
			}
			if(s > m)
				cout<<"invalid"<<endl;
			else
				cout<<A[s].v<<endl;
		}
		
	}
	
	return 0;
}