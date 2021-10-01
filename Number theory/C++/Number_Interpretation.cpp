/* DSA - Number Theory in C++ - Number Interpretation

Question: Find two positive integers A and B, such that A-B=N where N is a given positive integer and the number of distinct prime factors of A and B are equal.

Constraints: 1<= N <= 10^16
             1<= A, B <= 10^18

Example: 
	Input: 40
	Output: The first number is 80 and second number is 40
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int v[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};

int main() {
    ll n;
	cout<<"Enter N: ";
	cin>>n;
	if (n % 2 == 0) {
		ll a = 2 * n;
		ll b = n;
		cout<<"The first number is "<<a<<" and the second number is "<<b;
	} 
	
	else {
		int j = 0;
		while (n % v[j] == 0)
		{
		    j++;
	   	    ll a = n * v[j];
			ll b = n * (v[j] - 1);
			cout<<"The first number is "<<a<<" and the second number is "<<b;
		}
	}	
	return 0;
}           
