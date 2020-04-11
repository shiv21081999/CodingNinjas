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

void DFS(vector<int> *edges, int s, bool *visited, stack<int> &track)
{
	visited[s] = true;
	for (int i = 0; i < edges[s].size(); i++)
	{
		int adjacent = edges[s][i];
		if(!visited[adjacent])
		{
			DFS(edges, adjacent, visited, track);
		}
	}
	track.push(s);
}

void DFS1(vector<int>* edges, int s, bool*visited, unordered_set<int>* component)
{
	visited[s] = true;
	component->insert(s);
	for (int i = 0; i < edges[s].size(); i++)
	{
		int adjacent = edges[s][i];
		if(!visited[adjacent])
		{
			DFS1(edges, adjacent, visited, component);
		}
	}
	
}

unordered_set<unordered_set<int>*>* kosaraju(vector<int> *edges, vector<int> *edgesT, int n)
{
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	stack<int> track;
	for (int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			DFS(edges, i, visited, track);
		}
	}
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	while(!track.empty())
	{
		int node = track.top();
		track.pop();
		if(visited[node])
			continue;
		unordered_set<int>* component = new unordered_set<int>();
		DFS1(edgesT, node, visited, component);
		output->insert(component);
	}
	return output;
}

int32_t main(){
	while(true)
	{
		int n, e;
		cin>>n;
		if(n == 0)
			break;
		cin>>e;
		vector<int>* edges = new vector<int>[n];
		vector<int>*edgesT = new vector<int>[n];
		for (int i = 0; i < e; i++)
		{
			int f,s;
			cin>>f>>s;
			edges[f-1].pb(s-1);
			edgesT[s-1].pb(f-1);
		}

		unordered_set<unordered_set<int>*>* output = kosaraju(edges, edgesT, n);
		unordered_set<unordered_set<int>*>::iterator it = output->begin();
		vector<int> ans;
		while(it != output->end())
		{
			unordered_set<int>::iterator it1 = (*it)->begin();
			bool flag = true;
			while(it1 != (*it)->end())
			{
				for (int i = 0; i < edges[(*it1)].size(); i++)
				{
					int adjacent = edges[*it1][i];
					if((*it)->count(adjacent) == 0)
					{
						flag = false;
						break;
					}
				}
				if(!flag)
				{
					break;
				}
				it1++;
			}
			if(flag)
			{
				// cout<<"here"<<endl;
				it1 = (*it)->begin();
				while(it1 != (*it)->end())
				{
					ans.pb((*it1)+1);
					it1++;
				}
			}
			it++;
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		delete [] edges;
		delete [] edgesT;
		delete output;
	}
	return 0;
}