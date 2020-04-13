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
		int count = 0;
		trieNode *left = NULL;
		trieNode *right = NULL;
};


void deleteTrie(trieNode *head)
{
	if(head->right)
		deleteTrie(head->right);
	else
	 deleteTrie(head->left);

	 free(head);
	 return;
}



void insertRec(trieNode *head, int n, int p)
{
	if(p == -1)
		return;
	int bit = (n>>p)&1;
	if(bit == 1)
	{
		if(!head->right)
		{
			trieNode *newnode = new trieNode();
			newnode->count = 1;
			head->right = newnode;
			// head->count++;
		}
		else
		{
			head->right->count++;
		}
		
		insertRec(head->right, n, p-1);
		// if(head->left)
		// 	head->count = head->right->count + head->left->count;
		// else
		// 	head->count = head->right->count;
	}
	else
	{
		if(!head->left)
		{
			trieNode *newnode = new trieNode();
			newnode->count= 1;
			head->left = newnode;
			// head->count++;
		}
		else
		{
			head->left->count++;
		}
		insertRec(head->left, n, p-1);
		// if(head->right)
		// 	head->count = head->right->count + head->left->count;
		// else
		// 	head->count = head->left->count;
	}
	// cout<<bit<<" "<<head->count<<endl;

}

int query(trieNode *head, int val, int p, int k)
{
	if(head == NULL)
		return 0;
	if(p == -1)
	{
		return 0;
	}
	int bitv = (val>>p)&1;
	int bitk = (k>>p)&1;
	int ans = 0;
	if(bitk ==0)
	{
		if(bitv == 0)
		{
			return query(head->left, val,p-1, k);
		}
		else
		{
			return query(head->right, val, p-1, k);
		}
		
	}
	else
	{
		if(bitv == 0)
		{
			if(head->left)
			{
				return head->left->count + query(head->right, val, p-1, k);
			}
			return query(head->right, val, p-1, k);
		}
		if(bitv == 1)
		{
			if(head->right)
			{
				return head->right->count + query(head->left, val, p-1, k);
			}
			return query(head->left, val, p-1, k);
		}
	}
	return 0;
}

int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int *arr = new int[n];
		trieNode *head = new trieNode();
		insertRec(head, 0, 31);
		for (int i = 0; i < n; i++)
		{
			cin>>arr[i];
		}
		int xorSoFar = 0;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			xorSoFar = xorSoFar^arr[i];
			// cout<<xorSoFar<<endl;
			count += query(head, xorSoFar, 31, k);
			insertRec(head, xorSoFar, 31);

		}
		cout<<count<<endl;
		delete [] arr;
		// deleteTrie(head);
	}
	return 0;
}