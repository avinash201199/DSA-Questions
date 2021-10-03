#include<iostream>
using namespace std;
void UniqueBST(int n,int *arr){
    if(n==0||n==1){
        arr[0]=1;
        arr[1]=1;
        return ;
    }
    UniqueBST(n-1,arr);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=arr[i]*arr[n-i-1];

    }
    if(arr[n]<0){
        arr[n]=ans;
    }
}

int numtrees(int n){
    int arr[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=-1;
    }
    UniqueBST(n+1,arr);
    return arr[n];
}

int main(){
    int n;
    cout<<"Enter a NUmber :";
    cin>>n;
    cout<<numtrees(n)<<endl;
}