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

int root(int *parent , int node)
{
	if(parent[node] == node)
		return node;
	parent[node] = parent[parent[node]];
	return root(parent, parent[node]);
}

bool bipartite(unordered_set<int> *edges, int n)
{
	unordered_set<int> *sets = new unordered_set<int>[2];
	queue<int> q;
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			q.push(i);
			sets[0].insert(i);
			while(!q.empty())
			{
				int current = q.front();
				q.pop();
				visited[current] = true;
				int currentSet = sets[0].count(current) > 0 ? 0 : 1;
				if(edges[current].size() == 0)
					continue;
				for (int j = 0; j < n; j++)
				{
					int neighbor = edges[current].count(j) > 0 ? j : -1;
					if(neighbor == -1)
						continue;
					if(sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0)
					{
						sets[1-currentSet].insert(neighbor);
						q.push(neighbor);
					}
					else if(sets[currentSet].count(neighbor) > 0)
					{
						return false;
					}
				}
				
			}
		}
	}
	delete [] sets;
	delete [] visited;
	return true;
}

void union_rank(int *parent, int *rank, int a, int b)
{
	int roota = root(parent, a);
	int rootb = root(parent, b);
	if(rank[roota] > rank[rootb])
	{
		parent[rootb] = roota;
	}
	else if(rank[roota] < rank[rootb])
	{
		parent[roota] = rootb;
	}
	else
	{
		parent[roota] = rootb;
		rank[rootb]++;
	}
	
}

int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		bool flag = true;
		int **arr = new int*[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = -1;
			}
			
		}
		for (int i = 0; i < q; i++)
		{
			int f,s,val;
			cin>>f>>s>>val;
			arr[f-1][s-1] = val;
		}
		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < n; j++)
		// 	{
		// 		cout<<arr[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(i == j && arr[i][j] != 0 && arr[i][j]!=-1)
				{
					cout<<"no"<<endl;
					flag = false;
					break;
				}
				if(arr[i][j] != -1 && arr[j][i] != -1)
				{
					if(arr[i][j] != arr[j][i])
					{
						cout<<"no"<<endl;
						flag = false;
						break;
					}
				}
			}
			if(!flag)
			{
				break;
			}
			
		}
		if(!flag)
		{
			continue;
		}
		int *parent = new int[n];
		int *rank = new int[n];
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(arr[i][j] == 0)
				{
					int rooti = root(parent, i);
					int rootj = root(parent, j);
					if(rooti != rootj)
					{
						union_rank(parent, rank, i, j);
					}
				}
			}
			
		}
		unordered_set<int>* edges = new unordered_set<int>[n];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(arr[i][j] == 1)
				{
					int rooti = (parent, i);
					int rootj = (parent, j);
					if(rooti == rootj)
					{
						cout<<"no";
						flag = false;
						break;
					}
					edges[i].insert(j);
					edges[j].insert(i);
				}
			}
			if(!flag)
			{
				break;
			}
			
			
		}
		if(!flag)
		{
			continue;
		}
		// cout<<endl;
		// for (int i = 0; i < n; i++)
		// {
		// 	cout<<i<<"  ";
		// 	unordered_set<int>::iterator it = edges[i].begin();
		// 	while(it != edges[i].end())
		// 	{
		// 		cout<<(*it)<<" ";
		// 		it++;
		// 	}
		// 	cout<<endl;
		// }
		if(bipartite(edges, n))
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
		delete [] edges;
		delete [] rank;
		delete [] parent;
		for (int i = 0; i < n; i++)
		{
			delete [] arr[i];
		}
		delete [] arr;
	}
	return 0;
}