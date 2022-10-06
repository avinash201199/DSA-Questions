#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> arr(n, 0);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int i=0, parentindex=0, childindex=0;
    while(i<n){
        childindex=i;
        parentindex= (childindex-1)/2;
        i++;
        if(arr[parentindex]<arr[childindex]) cout<<"NO"<<endl;
        else continue;
        // while(arr[parentindex]<arr[childindex]){
        //     int temp = arr[parentindex];
        //     arr[parentindex] = arr[childindex];
        //     arr[childindex] = temp;
        //     childindex = parentindex;
        //     parentindex = (childindex-1)/2;
        // }
    }
    cout<<"YES"<<endl;


    return 0;

}