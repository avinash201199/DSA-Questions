
#include <bits/stdc++.h>
using namespace std;

int maximum(int a, int b)
{
	return (a > b)? a : b;
}
int LongestCommonSubsequence( string X, string Y, int m, int n )
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m-1] == Y[n-1])
		return 1 + LongestCommonSubsequence(X, Y, m-1, n-1);
	else
		return maximum(LongestCommonSubsequence(X, Y, m, n-1), LongestCommonSubsequence(X, Y, m-1, n));
}



int main()
{
	string X;
	string Y;
	
	cin>>X;
	cin>>Y;
	
	int m = X.length();
	int n = Y.length();
	
	cout<<"Length of LongestCommonSubsequence is "<< LongestCommonSubsequence( X, Y, m, n ) ;
	
	return 0;
}

