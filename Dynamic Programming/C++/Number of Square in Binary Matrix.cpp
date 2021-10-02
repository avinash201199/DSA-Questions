// to find the maximum area of the square in a binary matrix

#include<bits/stdc++.h>
using namespace std;

// helper function
// bottom up approach
int countSq(vector<vector<int>> &matrix, int m, int n)
{
    vector<vector<int>> dp(m, vector<int> (n, 0));
    int ans = 0;
    for(int i = m-1; i>=0; i--)
    {
        for(int j = n-1; j>=0; j--)
        {
            // if it is last row or a last column then the maximum area would be either 0 or 1
            if(i == m-1 || j == n-1)
                dp[i][j] = matrix[i][j];
            //if at any index the value is 0 then the square at that position would be zero
            else if(matrix[i][j] == 0)
                dp[i][j] = 0;
            //else we will check all the adjacent index i.e right, down, down right diagonal and find min val + 1
            else
            {
                int mn = min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
                dp[i][j] = mn + 1;
            }
            ans = ans + dp[i][j];           // update the ans by adding all the ans
        }
    }

    return ans;
}

int main()
{
    int m, n;
    cout<<"Enter the number of rows and columns::";
    cin>>m>>n;

    vector<vector<int>> matrix(m, vector<int> (n));

    //create the binary matrix
    cout<<"Enter the elements of the matrix::";
    for(int i = 0; i<m; i++)
        for(int j = 0; j<n; j++)
            cin>>matrix[i][j];

    cout<< countSq(matrix, m, n);
    return 0;
}