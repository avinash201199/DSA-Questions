// Finding large power of a^n in log(n) time

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007
lli power(lli a, lli n )
{
	lli res = 1;
	
	while(n)
	{
		if(n % 2 == 1)
		{
			res = ((res % mod) * (a % mod)) % mod;
			n--;
		}
		
		else
		{
			a = ((a % mod) * (a % mod)) % mod;
			n /= 2;
		}
	}
	
	return res;
}
int main() {
  lli b,p;
   b=2;
 p=1000000;
 cout<<power(b,p)<<endl;
}
