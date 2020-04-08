#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define MAXN 102
// const int N = 100005, M = 11;
int mod = 1000000007;

int dx[] = {1,-1,1,-1,0,0,-1,1};
int dy[] = {1,-1,-1,1,1,-1,0,0};

bool isPossible(char graph[][102], int row, int col, int n, int m, char str[], int index, bool **visited)
{
    if(index == 11)
    {
        return true;
    }
    if(row == n || col == m || row<0 || col<0)
    {
        return false;
    }
    bool flag = false;

    if(graph[row][col] == str[index] && !visited[row][col])
    {
        // cout<<row<<" "<<col<<" "<<graph[row][col]<<" "<<str[index]<<" "<<index<<" "<<visited[row][col]<<endl;
        visited[row][col] = true;
        for (int i = 0; i < 8; i++)
        {
            flag = isPossible(graph, row + dx[i], col + dy[i], n, m, str, index +1, visited);
            if(flag == true)
                return flag;
        }
        visited[row][col] = false;
        
    }
    return false;
}

int solve(char graph[][MAXN],int n, int m)
{
    
	bool **visited = new bool*[n];
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
		for(int j = 0 ; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
    
    
    char str[] = "CODINGNINJA";
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(graph[i][j] == 'C')
            {
                flag = isPossible(graph, i, j, n, m, str, 0, visited);
                if(flag == true)
                    return 1;
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        delete [] visited[i];
    }
    delete [] visited;
    return 0;
    
}

int32_t main(){
    int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
    return 0;
}