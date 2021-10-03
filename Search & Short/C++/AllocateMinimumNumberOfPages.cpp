/*
hacktoberfest2021

ALLOCATE MINIMUM NUMBER OF PAGES:

Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Example :

Input : pages[] = {12, 34, 67, 90}
        m = 2
Output : 113
Explanation:
            There are 2 number of students. Books can be distributed in following fashion : 
              1) [12] and [34, 67, 90]
                  Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
              2) [12, 34] and [67, 90]
                  Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
              3) [12, 34, 67] and [90]
                  Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

            Of the 3 cases, Option 3 has the minimum pages = 113. 

*/

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int maxElement(int A[], int N){
        int maxEle=A[0];
        for(int i=1; i<N; i++)
            maxEle=max(maxEle, A[i]);
        return maxEle;
    }
    int sumOfArray(int A[], int N){
        int sum=A[0];
        for(int i=1; i<N; i++)
            sum+=A[i];
        return sum;
    }
    bool isValid(int A[], int N, int M, int mid){
        int student=1;
        int sum=0;
        for(int i=0; i<N; i++){
            sum+=A[i];
            if(sum>mid){
                student++;
                sum=A[i];
            }
            if(student>M)
                return false;
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M)
            return -1;
        int start=maxElement(A, N);
        int end=sumOfArray(A, N);
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isValid(A, N, M, mid)==true){
                res=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return res;
    }
};



int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
