#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define NMAX 55
char cake[NMAX][NMAX];
const int N = 100005, M = 11;
int mod = 1000000007;



int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int getMaxOnes(char cake[NMAX][NMAX], int n, bool **visited, int row, int col)
{
    if(row < 0 || col <0 || row == n || col == n)
    {
        return 0;
    }
    if(cake[row][col] == '0')
        return 0;
    int ans = 0;
    if(!visited[row][col])
    {
        visited[row][col] = true;
        for (int i = 0; i < 4; i++)
        {
			ans+= getMaxOnes(cake, n, visited, row + dx[i], col + dy[i]); 
        }
        return ans+1;
    }
    return ans;
}

int solve(int n,char cake[NMAX][NMAX])
{
    bool **visited = new bool*[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
        
    }
    int finalmax = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(cake[i][j] == '1')
            {
                // for (int k = 0; k < n; k++)
                // {
                //     for (int l = 0; l < n; l++)
                //     {
                //         visited[k][l] = false;
                //     }
                    
                // }
                int max = 0;
                if(!visited[i][j])
                    max = getMaxOnes(cake, n, visited, i, j);
                if(max > finalmax)
                    finalmax = max;
            }
        }
        
    }
    
    return finalmax;
}

int32_t main(){
    int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
    return 0;
}