//Question
//Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum

#include<bits/stdc++.h>
using namespace std;
int Checksum(int arr[],int sum,int n){
   int t[n+1][sum+1];
   for(int i=0;i<=n;i++){
       for(int j=0;j<=sum;j++){
           if(i==0){
              t[i][j]=0;
              
           }
           if(j==0){
               t[i][j]=1;
           }
       }
   }
   for(int i=1;i<n+1;i++){
       for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
               t[i][j]=(t[i-1][j-arr[i-1]]||t[i-1][j]);
           }
           if(arr[i-1]>j){
               t[i][j]=t[i-1][j];
           }
          
       }
   }
   return t[n][sum];
}
int main(){
    int n=5;
    int arr[n]={2,3,7,8,10};
    int sum=11;
    cout<<Checksum(arr,sum,n)<<endl;
   
    
}