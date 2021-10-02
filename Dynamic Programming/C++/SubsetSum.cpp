/* SubsetSum problem

Ques:-
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

Input:-
5 12
1 5 3 7 4

Output:-
Yes

*/

#include <bits/stdc++.h>

using namespace std;

bool isSubset(int arr[],int n,int sum){
    bool dp[n+1][sum+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0){
                dp[i][j]=false;
            }
            // considering empty subset as true;
            if(j==0){
                dp[i][j]=true;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                // considering two cases: including the given element and not including the given element.
                // if either is true -> set true;

                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][sum];


}

int main(){

    int n,sum;
    cin>>n>>sum;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(isSubset(arr,n,sum)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}