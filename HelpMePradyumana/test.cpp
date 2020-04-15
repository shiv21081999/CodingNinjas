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
	bool isWord = false;
	// int count;
	trieNode* children[26];
};
// unordered_set<string> values;
void DFS(trieNode* head, string ans)
{
	if(head->isWord)
	{
		 cout<<ans<<endl;
	}
	for (int i = 0; i < 26; i++)
	{
		if(head->children[i])
		{
			char a = i+'a';
			DFS(head->children[i],ans+a);
		}
	}
	
}

void insert(trieNode *head, string str)
{
	trieNode *curr = head;
	int n = str.length();
	for (int i = 0; i < n; i++)
	{
		int val = str[i];
		if(!curr->children[val - 97])
		{
			trieNode *newnode = new trieNode();
			curr->children[val-97] = newnode;
		}
		curr = curr->children[val - 97];
	}
	curr->isWord = true;
}

void printAllPossible(trieNode *head, string pre)
{
	int n = pre.length();
	trieNode *curr = head;
	for (int i = 0; i < n; i++)
	{
		int val = pre[i];
		if(!curr->children[val - 97])
		{
			insert(head, pre);
			cout<<"No suggestions"<<endl;
			return;
		}
		curr = curr->children[val - 97];
	}
	DFS(curr, pre);
}

int32_t main(){
	int n,q;
	cin>>n;
	trieNode *head = new trieNode();
	for (int i = 0; i < n; i++)
	{ 
		string str;
		cin>>str;
		// values.insert(str);
		insert(head, str);
	}
	cin>>q;
	// cout<<"here"<<endl;
	for (int i = 0; i < q; i++)
	{
		string str;
		cin>>str;
		printAllPossible(head, str);
	}
	
	return 0;
}