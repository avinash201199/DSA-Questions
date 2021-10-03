/*
Reversort is an algorithm to sort a list of distinct integers in increasing order. The algorithm is based on the "Reverse" operation. Each application of this operation reverses the order of some contiguous part of the list.

The pseudocode of the algorithm is the following:

Reversort(L):
  for i := 1 to length(L) - 1
    j := position with the minimum value in L between i and length(L), inclusive
    Reverse(L[i..j])
After i−1 iterations, the positions 1,2,…,i−1 of the list contain the i−1 smallest elements of L, in increasing order. During the i-th iteration, the process reverses the sublist going from the i-th position to the current position of the i-th minimum element. That makes the i-th minimum element end up in the i-th position.

For example, for a list with 4 elements, the algorithm would perform 3 iterations. Here is how it would process L=[4,2,1,3]:

i=1, j=3⟶L=[1,2,4,3]
i=2, j=2⟶L=[1,2,4,3]
i=3, j=4⟶L=[1,2,3,4]
The most expensive part of executing the algorithm on our architecture is the Reverse operation. Therefore, our measure for the cost of each iteration is simply the length of the sublist passed to Reverse, that is, the value j−i+1. The cost of the whole algorithm is the sum of the costs of each iteration.

In the example above, the iterations cost 3, 1, and 2, in that order, for a total of 6.

Given the initial list, compute the cost of executing Reversort on it.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int k=0;

int rec(int start, int end, int index, int c, int arr[])
{
	if(start == end)
		return start;
	else if(start > end)
		return -1;
	else if(c>end || c<start)
		return -1;

	int res = rec(start, end - index + 1, index + 1, c, arr);
	if(res == c)
	{
		arr[k++] = 1;
		return res;
	}

	res = rec(start + index - 1, end, index + 1, c, arr);
	if(res == c)
	{
		arr[k++] = index;
		return res;
	}
	return -1;
}

void solve(int tc)
{
	int arr[101];
	k=0;
  	int n, c;
  	cin>>n>>c;
  	int res[n];

  	int start = n-1;
  	int end = (n*(n+1) - 2)/2;

  	if(c<start || c>end)
  	{
		cout<<"Case #"<<tc<<": "<<"IMPOSSIBLE"<<endl;
		return;  	
  	}

  	int r = rec(start, end, 2, c, arr);
  	arr[k++] = 1;
  	
  	int s = 0, e = n-1, i = 1;
  	int idx = s;
  	for(i = 0 ; i<n ; i++)
  	{
  		if(arr[i] == 1)
  		{
  			res[idx] = i+1;
  			if(idx == s)
  			{
  				s++;
  				idx++;
  			}
  			else if(idx == e)
  			{
  				e--;
  				idx--;
  			}
  		}
  		else
  		{
  			if(idx == s){
  				idx = e;
  				res[idx] = i+1;
  				idx--;
  				e--;
  			}
  			else if(idx == e){
  				idx = s;
  				res[idx] = i+1;
  				idx++;
  				s++;
  			}
		}
	}

  	cout<<"Case #"<<tc<<": ";
  	for(i=0 ; i<n ; i++)
  		cout<<res[i]<<" ";
  	cout<<endl;

}

int main()
{
  int t;
  cin>>t;
  for(int i=1 ; i<=t ; i++)
    solve(i);
  return 0;
}
