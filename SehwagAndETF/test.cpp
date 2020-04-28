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

vector<int> primes;
int arr[N];
int arr1[N];
void seive(int *input)
{
	for (int i = 1; i < 1000001LL; i++)
	{
		input[i] = i;
	}
	
	for (int i = 2; i <= 1000000; i++)
	{
		if(input[i]==i)
		{
			primes.pb(i);
			input[i] = i - 1;
			int temp = i+i;
			while(temp <= 1000000)
			{
				input[temp] = (input[temp]*(i-1))/i;
				temp+=i;
			}
		}
	}
}

int32_t main(){
	int *totient = new int[1000001]();
	seive(totient);
	// for (int i = 0; i < 1000001; i++)
	// {
	// 	cout<<totient[i]<<" ";
	// }
	// cout<<endl;
	int t;
	scanf("%lli",&t);
	while(t--){
		int l,r,k;
		scanf("%lli%lli%lli",&l,&r,&k);
		int n = r-l+1;
		if(r <= 1000000)
		{
			int count = 0;
			for (int i = l; i < r+1; i++)
			{
				if(totient[i]%k == 0)
					count++;
			}
			long double ans = ((double)(count))/((double)(n));
			printf("%.6Lf\n",ans);
			continue;
		}
		// int *arr = new int[n];
		// int *arr1 = new int[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = i+l;
			arr1[i] = i+l;
		}
		for (auto prime : primes)
		{
			int start = (l/prime)*prime;
			for (int i = start; i <= r; i+=prime)
			{
				if(i<l)
					continue;
				arr[i-l] = (arr[i-l]*(prime-1))/prime;
				while(arr1[i-l]%prime==0)
				{
					arr1[i-l]/=prime;
				}
			}
			
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if(arr[i] == i+l)
			{
				arr[i] = arr[i]-1;
				if(arr[i]%k == 0)
					count++;
				continue;
			}
			if(arr1[i]!=1)
			{
				arr[i] = arr[i]/arr1[i];
				arr[i] = arr[i]*(arr1[i]-1);

			}
			if(arr[i]%k == 0)
				count++;
		}
		
		// cout<<"here"<<endl;

		// int count = 0;
		// for (int i = 0; i < n; i++)
		// {
		// 	if(arr[i]%k==0)
		// 		count++;
		// }
		long double ans = (double)(count)/(double)(n);
		printf("%.6Lf\n",ans);
		// delete [] arr;
		// delete [] arr1;
	}
	delete [] totient;
	return 0;
}