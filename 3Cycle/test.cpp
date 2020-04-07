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

int getThreeCycle(int **edges, int s, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(edges[s][i] == 1 && i!=s)
        {
            for (int j = 0; j < n; j++)
            {
                if(edges[i][j] == 1 && i!=j)
                {
                    if(edges[s][j] == 1)
                    {
                        count++;
                    }
                }
                
            }
        }
    }
    return count;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	int **edges = new int*[n];
    for (int i = 0; i < n; i++){
        edges[i] = new int[n];
    }
    for (int i = 0; i < m; i++){
        edges[u[i]-1][v[i]-1] = 1;
        edges[v[i]-1][u[i]-1] = 1;
    }
    // cout<<"hello"<<endl;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        
        count+= getThreeCycle(edges, i, n);

    }
    for (int i = 0; i < n; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
    return count/6;
}

int32_t main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
    return 0;
}