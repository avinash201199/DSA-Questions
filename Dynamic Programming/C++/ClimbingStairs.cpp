#include<iostream>

using namespace std;

int ClimbStairs(int n);

int main()
{
    cout << "Enter the number of stairs: ";
    int n;
    cin >> n;
    cout << ClimbStairs(n) << endl;
}

int ClimbStairs(int n)
{
    int dp[n+1];
    dp[0] = 1;     // If there the stairs are 0 and 1 in number, then the possible ways to climb are 1 and 1 respectively.
    dp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];     // To climb to nth stairs, the number of ways depends on the number of ways to climb (n-1)th and (n-2)th stairs
    }
    return dp[n];
}

  /* 
    
    *** Test Case 1 ***
    
    Enter the number of stairs: 6
    
    13

    *** Test Case 2 ***

    Enter the number of stairs: 56
    
    363076002

    Link to the problem: https://leetcode.com/problems/climbing-stairs/

   */