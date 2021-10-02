
/*Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation
 of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an 
 ascending order. You are given an list of numbers arr[ ] of size N.

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6} */

/* The time complexity of the below solution is O(N).
The space complexity of the below solution is O(1). */

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        
        int idx=-1;
        for(int i=N-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                idx=i;
                break;
            }
        }
        // if the array is in descending order the next permutation will be the array in reverse order. 
        if(idx==-1){
            reverse(arr.begin(),arr.end());
        }
        else{
            int prev=idx;
            for(int i=idx+1;i<N;i++){
                if(arr[i]>arr[idx-1] && arr[i]<arr[prev]){
                    prev=i;
                }
            }
            swap(arr[idx-1],arr[prev]);
            reverse(arr.begin()+idx,arr.end());
        }
        return arr;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        Solution ob;
        vector<int> ans = ob.nextPermutation(N,arr);
        for(int u: ans){
            cout<<u<<" ";
        }
        cout<<endl;
    }
    return 0;
}