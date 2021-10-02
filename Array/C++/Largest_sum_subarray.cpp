/* Given an array A of size N, print the largest sum of contiguos subarray.

Input:
First line contains an integer denoting the test cases 'T'. T testcases follow. Each testcase contains two lines of input. First line contains N the size of the array A. The second line contains the elements of the array.
Output:
For each testcase, in a new line, print largest sum which you get of contigous subarray.

Constraints:
1 <= T <= 100
1 <= N <=100
0 <= Ai <= 100
Example:

Input:
1
5
-4 1 -1 2 3

Output:
5

Explaination: The last two numbers together make the sum 5 and they arey contigous also.

Hint: Try to ignore the negative numbers because they will decrese our sum.

Approach: The best and optimized approch would be of kadanes algorithm which will take O(N) time complexity.

*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    int max=0, tmax=0, n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(i==0)
        max=a[i];
        else
        max=max+a[i];
        if(max<0)
        max=0;
        tmax=tmax<max?max:tmax;
    }
    cout<<"Largest sum contiguous subarray is: "<<tmax<<endl;}
    
    return 0;
}