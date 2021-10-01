/* 
Partition a given string A such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of A.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string A, int i, int j){
    for(int s=i, e=j;s<=e;s++, e--){
        if(A[s]!=A[e])
            return false;
    }
    return true;
}
 
int solve(string A, int i, int j, vector<vector<int>>& dp){
    if(i>=j)
        return 0;
    if(isPalindrome(A, i, j))
        return 0;
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int left, right;
        if(dp[i][k]!=-1)
            left=dp[i][k];
        else{
            left=solve(A,i,k,dp);
            dp[i][k]=left;
        }
        
        if(dp[k+1][j]!=-1)
            right=dp[k+1][j];
        else{
            right=solve(A,k+1,j,dp);
            dp[k+1][j]=right;
        }
        ans=min(ans, left+right+1);
    }
    return dp[i][j]=ans;
}

int main(){
    string A;
	cin>>A;
	
    int n=A.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	
    cout<<solve(A, 0, n-1, dp);

    return 0;
}
