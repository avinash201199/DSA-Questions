#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    priority_queue<int, vector<int>, greater<int>> p;
    int i=0;

    for(i=0; i<k; i++){
        p.push(arr[i]);

    }
    while(i<n){
        if(arr[i]>p.top()){
            p.push(arr[i]);
            p.pop();
        }
        i++;
    }

    cout<<p.top()<<endl;

    return 0;

}