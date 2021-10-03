#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000]={0},i,j;
string lps(string str1,string str2,int l,int r)
{
	 if(l==0||r==0) 
	 {
	 	return string("");
	 }
	 else if(str1[l-1]==str2[r-1])
	 {
	 	return lps(str1,str2,l-1,r-1)+str1[l-1]; 
	 } 
	 else if(dp[l-1][r]>dp[l][r-1])
	 {
	 	return lps(str1,str2,l-1,r); //else recurse for minimum of them.
	 }
	 return lps(str1,str2,l,r-1);
}

int lps_l(string str1,string str2,int n) //lcs of string with its reverse gives length of lps
{
 for(i=1;i<=n;i++)
 {
 	for(j=1;j<=n;j++)
 	{
 		if(str1[i-1]==str2[j-1]) 
		{
 			dp[i][j]=dp[i-1][j-1]+1; 
 		}
	 	else
	 	{
	 		dp[i][j]=max(dp[i-1][j],dp[i][j-1]); //checking min between str1[0-i]str2[0-(j-1)] and str1[0-(i-1)]str2[0-j]
	 	}
    }
 }
 return dp[n][n];
}
int main()
{
 int n;
 string s;
 cout<<"Enter the string for finding longest palindrome subsequence:";
 cin >> s;
 n = s.length();

 string rstr=s;
 reverse(rstr.begin(),rstr.end());
 int len=lps_l(s,rstr,n);
 cout<<"The length of the longest palindromic subsequence is : "<<lps(s,rstr,n,n)<<"\nlength : "<<len<<endl;
 return 0;
}
