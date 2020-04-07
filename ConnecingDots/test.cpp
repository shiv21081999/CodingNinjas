#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define MAXN 51
const int N = 100005, M = 11;
int mod = 1000000007;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool getCycle(char board[][MAXN], int row, int col, char color, int k, int n, int m, bool **visited, int previ, int prevj)
{
    if(row == n || col == m || row<0 || col<0)
        return false;
    if(visited[row][col] && board[row][col] == color && k>=4)
    {
        return true;
    }
    bool flag = false;
    if(!visited[row][col] && board[row][col] == color)
    {
        visited[row][col] = true;
        for (int i = 0; i < 4; i++)
        {
            if(row+dx[i] != previ || col+dy[i] != prevj)
            {
                // cout<<row<<" "<<col<<endl;
                flag = getCycle(board, row+dx[i], col+dy[i], color, k+1, n, m, visited, row, col);
            }
            if(flag == true)
                return true;
        }
        
    }
    return false;
}
int solve(char board[][MAXN],int n, int m)
{
	char colors[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool **visited = new bool*[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
    }
    bool flag = false;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if(board[j][k] == colors[i])
                {
                    for (int l = 0; l < n; l++)
                    {
                        for (int o = 0; o < m; o++)
                        {
                            visited[l][o] = false;
                        }
                        
                    }
                    flag = getCycle(board, j, k, colors[i], 0, n, m, visited, -1, -1);
                    if(flag == true)
                        return 1;
                }
            }
            
        }
        
    }
    return 0; 
}

int32_t main(){
    int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
    return 0;
}