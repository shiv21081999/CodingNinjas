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

int dx[] = {-2,-2,2,2,-1,-1,1,1};
int dy[] = {-1,1,-1,1,-2,2,-2,2};

int DFS(vector<pair<int,int>> (**graph), bool **visited, int i, int j)
{
    visited[i][j] = true;
    int ans = 1;
    for (int k = 0; k < graph[i][j].size(); k++)
    {
        int x = graph[i][j][k].F;
        int y = graph[i][j][k].S;
        if(!visited[x][y])
        {
            ans = (ans + DFS(graph, visited, x, y)%mod);
        }
    }
    
    return ans;
}
void make_graph(vector<pair<int, int>> **graph, int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == 1)
            {
                graph[i][j].pb(make_pair(i,j));

                for (int k = 0; k < 8; k++)
                {
                    int row = dx[k] + i;
                    int col = dy[k] + j;
                    if((row >=0 && col >= 0) && (row <= n-1 && col <=m-1))
                    {
                        if(arr[row][col] == 1)
                            graph[i][j].pb(make_pair(row, col));
                    } 
                }
                
            }
        }
        
    }
    
}
int32_t main(){
    int t;
    cin>>t;
    int *fact = new int[1000001];
    fact[0] = 1;
    for (int i = 1; i < 1000001; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
    
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        int **arr = new int*[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = 0;
            }
            
        }
        for (int i = 0; i < q; i++)
        {
            int f,s;
            cin>>f>>s;
            arr[f-1][s-1] = 1;
        }
        
        vector<pair<int, int>> **graph = new vector<pair<int,int>>*[n];
        for (int i = 0; i < n; i++)
        {
            graph[i] = new vector<pair<int,int>>[m];
        }
        make_graph(graph, arr, n, m);
        bool **visited = new bool*[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = new bool[m];
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = false;
            }
            
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(arr[i][j] == 1 && !visited[i][j])
                {
                    int members = DFS(graph, visited, i, j);
                    ans.pb(members);
                }
            }
            
        }
        int finalans = 1;
        for (int i = 0; i < ans.size(); i++)
        {
            finalans = ((finalans%mod)*(fact[ans[i]]%mod))%mod;
        }
        cout<<finalans<<endl;
        for (int i = 0; i < n; i++)
        {
            delete [] arr[i];
            delete [] visited[i];
        }
        delete [] arr;
        delete [] visited;
    }
    delete [] fact;
    return 0;
}