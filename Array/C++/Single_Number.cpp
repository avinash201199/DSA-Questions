// Enter the size of array: 7
// Enter the elements of the array: 1 1 2 3 3 2 9

// Single Number = 9

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>a(n);
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i<n; i++)
        cin>>a[i];
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans ^= a[i];
    }
    cout<<"\nSingle Number = "<<ans;
    return 0;
}
