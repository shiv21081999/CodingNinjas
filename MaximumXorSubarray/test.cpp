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
	trieNode *left = NULL;
	trieNode *right = NULL;
};

void insert(trieNode *head, int val)
{
	trieNode *curr = head;
	for (int i = 31; i >= 0; i--)
	{
		int bit = (val >> i)&1;
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
				trieNode *new_node = new trieNode();
				curr->left = new_node;
			}
			curr = curr->left;
		}
		
	}
	
}

int insert_and_return(trieNode *head, int val)
{
	insert(head, val);
	trieNode *curr = head;
	int maxXor = 0;
	for (int i = 31; i >= 0; i--)
	{
		int bit = (val >> i)&1;
		// cout<<bit<<endl;
		if(bit == 1)
		{
			if(curr->left)
			{
				maxXor += pow(2,i);
				curr = curr->left;
			}
			else
			{
				if(curr->right)
				{
					curr = curr->right;
				}
			}
			
		}
		else
		{
			if(curr->right)
			{
				maxXor += pow(2, i);
				curr = curr->right;
			}
			else
			{
				if(curr->left)
					curr = curr->left;
			}
			
		}
	}
	return maxXor;
}

int32_t main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	int xor_sorfar = 0;
	trieNode *head = new trieNode();
	int finalMax = INT_MIN;
	insert(head, 0);
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		xor_sorfar = xor_sorfar^arr[i];
		int maxSoFar = insert_and_return(head, xor_sorfar);
		if(maxSoFar > finalMax)
			finalMax = maxSoFar;
	}
	
	cout<<finalMax<<endl;
	delete [] arr;
	return 0;
}