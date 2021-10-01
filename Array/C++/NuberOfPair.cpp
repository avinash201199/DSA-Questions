/*
You are given an array a of n integers. Find the number of pairs (i,j) (1≤i<j≤n) where the sum of ai+aj is greater than or equal to l and less than or equal to r (that is, l≤ai+aj≤r).

For example, if n=3, a=[5,1,2], l=4 and r=7, then two pairs are suitable:

i=1 and j=2 (4≤5+1≤7);
i=1 and j=3 (4≤5+2≤7).
Input
The first line contains an integer t (1≤t≤104). Then t test cases follow.

The first line of each test case contains three integers n,l,r (1≤n≤2⋅105, 1≤l≤r≤109) — the length of the array and the limits on the sum in the pair.

The second line contains n integers a1,a2,…,an (1≤ai≤109).

It is guaranteed that the sum of n overall test cases does not exceed 2⋅105.

Output
For each test case, output a single integer — the number of index pairs (i,j) (i<j), such that l≤ai+aj≤r.
*/

// Numer of Pairs
// Use binary seacrh insted of linear search
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
ll minimum(ll x, ll y)
{
   return (x>y)?y:x;
}
ll maximum(ll x, ll y)
{
   return (x>y)?x:y;
}
void copy(int a[], int b[], int n)
{
   for(int i=0 ; i<n ; i++)
      a[i] = b[i];
}
//**************************************************************
ll lower(ll x, vector<ll> &v) {
   if(x<=0) return 0;

   ll n = v.size();
   ll res = 0, l = 0, u = n-1;
   while(l<=u)
   {
      ll m=l+(u-l)/2;
      if(v[m]>=x){
         res = m;
         u = m-1;
      }
      else
         l = m+1;
   }
   return res;
}

ll upper(ll x, vector<ll> &v)
{
   if(x<=0)
      return 0;
   ll n=v.size();
   ll l = 0, u = n-1;
   ll ans = 0;
   while(l <= u){
      ll m = l+(u-l)/2;
      if(v[m]<=x){
         ans = m;
         l = m + 1;
      }
      else
         u = m - 1;
   }
   return ans;  
}

void solve()
{
   ll n, l, r;
   cin>>n>>l>>r;
   std::vector<ll> v(n);
   for(ll i=0 ; i<n ; i++)
      cin>>v[i];
   sort(all(v));
   ll res = 0;
   for(int i=0 ; i<n ; i++)
   {
      if(v[i] >= r)
         break;
      ll ind1 = lower(l-v[i], v);
      ll ind2 = upper(r-v[i], v);
      if(ind1<=i) ind1 = i+1;
      if(ind2<=i) continue;
      if(v[ind1]+v[i] < l || v[ind2]+v[i] > r)  continue;
      res += ind2-ind1+1;
   }
   cout<<res<<endl;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
      solve();
   return 0;
}
