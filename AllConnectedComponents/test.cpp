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
void printComponentDFS(int **edges, int s, int n, bool *visited, vector<int> &arr)
{
    visited[s] = true;
    arr.pb(s);
    for (int i = 0; i < n; i++)
    {
        if(i == s)
            continue;
        if(edges[s][i] == 1 && !visited[i])
        {
            printComponentDFS(edges, i, n, visited, arr);
        }
    }
}

void DFS(int **edges, int n){
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            arr.clear();
            printComponentDFS(edges, i, n, visited, arr);
            sort(arr.begin(), arr.end());
            for (int i = 0; i < arr.size(); i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
}

int32_t main(){
    int n, e;
    cin>>n>>e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++){
        edges[i] = new int[n];
    }
    for (int i = 0; i < e; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    DFS(edges, n);
    return 0;
}