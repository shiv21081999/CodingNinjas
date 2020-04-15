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

class trieNode{
	public:
		int weight;
		trieNode* children[26];
};

void insert(string str, trieNode *head, int weight)
{
	trieNode *curr = head;
	int n = str.length();
	for (int i = 0; i < n; i++)
	{
		char val = str[i];
		if(!curr->children[val-97])
		{
			trieNode *newnode = new trieNode();
			newnode->weight = weight;
			curr->children[val-97] = newnode;
		}
		if(curr->weight < weight )
			curr->weight = weight;
		curr = curr->children[val-97];
	}
	
}

int query(string str, trieNode *head)
{
	trieNode *curr = head;
	for (int i = 0; i < str.length(); i++)
	{
		char val = str[i];
		if(!curr->children[val - 97])
		{
			return -1;
		}
		curr = curr->children[val-97];
	}
	return curr->weight;
}

int32_t main(){
	int n,q;
	cin>>n>>q;
	trieNode *head = new trieNode();
	for (int i = 0; i < n; i++)
	{
		string str;
		int w;
		cin>>str>>w;
		insert(str, head, w);
	}
	for (int i = 0; i < q; i++)
	{
		string str;
		cin>>str;
		cout<<query(str, head)<<endl;
	}
	
	return 0;
}