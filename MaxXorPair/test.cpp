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
	trieNode *left;
	trieNode *right;
};

void insertNode(trieNode *head, int n)
{
	trieNode *curr = head;
	for (int i = 32 - 1; i >= 0; i--)
	{
		int bit = (n>>i)&1;
		if(bit == 1)
		{
			if(!curr->right)
			{
				trieNode *new_node = new trieNode();
				curr->right = new_node;
			}
			curr = curr->right;
		}
		else
		{
			if(!curr->left)
			{
				trieNode *new_Node = new trieNode();
				curr->left = new_Node;
			}
			curr = curr->left;
		}
		
	}
	
}

int getMaxXorPair(trieNode *head, int *arr, int n)
{
	int finalXor = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		trieNode *curr = head;
		int val = arr[i];
		int currXor = 0;
		for (int j = 32 - 1; j >= 0; j--)
		{
			int bit = (val >> j)&1;
			if(bit == 1)
			{
				if(curr->left)
				{
					currXor += pow(2, j);
					curr = curr->left;
				}
				else
				{
					curr = curr->right;
				}
				
			}
			else
			{
				if(curr->right)
				{
					currXor += pow(2,j);
					curr = curr->right;
				}
				else
				{
					curr = curr->left;
				}
				
			}
			
		}
		if(currXor > finalXor)
			finalXor = currXor;
		
	}
	return finalXor;
	
}

int32_t main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	trieNode *head = new trieNode();
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
		insertNode(head, arr[i]);
	}
	cout<<getMaxXorPair(head, arr, n)<<endl;
	delete [] arr;
	return 0;
}