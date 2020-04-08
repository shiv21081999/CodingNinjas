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
    int index;
    int weight;
};
class comp{
    public:
        bool operator() (const node &a, const node &b)
        {
            return a.weight > b.weight;
        }
};

int getmin(bool *visited, int *weight, int n)
{
    int minVertex = -1;
    int minweight = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i] && weight[i]<minweight)
        {
            minVertex = i;
            minweight = weight[i];
        }
    }
    return minVertex;
}

void printMST(int **edges, bool*visited, int n)
{
    int *parent = new int[n];
    int *weight = new int[n];
    for (int i = 0; i < n; i++)
    {
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < n-1; i++)
    {
        int minVertex = getmin(visited, weight, n);
        visited[minVertex] = true;
        for (int j = 0; j < n; j++)
        {
            if(edges[minVertex][j] !=0 && !visited[j])
            {
                if(weight[j] > edges[minVertex][j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
        
    }
    for (int i = 1; i < n; i++)
    {
        if(i<parent[i])
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        else
        {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        
    }
    delete [] parent;
    delete [] weight;
}

int32_t main(){
    int n, e;
    cin>>n>>e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++){
        edges[i] = new int[n];
    }
    for (int i = 0; i < e; i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s] = w;
        edges[s][f] = w;
    }
    
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    printMST(edges, visited, n);
    delete [] visited;
    return 0;
}