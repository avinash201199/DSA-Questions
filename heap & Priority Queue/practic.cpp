#include<bits/stdc++.h>
using namespace std;

int loopit( vector<long long int> &arr, vector<int> &ans, int n, int count){
    int res = (ans[0]-ans[1])/2, newans=0;

    for(int i=0; i<2*n; i++){
        if(res==0) break;
        if(arr[i]%2!=0) continue;
        else{
            while(count--){
                int k = arr[i]/2;
                if(k%2!=0){ arr[i]=k; newans++; ans[0]--; ans[1]++; res--; continue;}
                if(count!=0) arr[i]=k;
            } 
        }
    }
    newans = newans*count;

    if(res!=0){
        
        count++;
        newans+= loopit(arr, ans, 2*n, count);
        return newans;
    }else return newans;

}

void catc(){
    long long int n, sm=0;
    cin>>n;
    vector<long long int> arr(2*n, 0);
    vector<int> ans(2, 0);
    // vector<long long int> ans(n, 0);
    for(int i=0; i<2*n; i++){
        cin>>arr[i];
        if(arr[i]%2!=0) ans[1]++;
        else ans[0]++;
    }

    if(ans[0]==ans[1]){
        cout<<0<<endl;
        return;
    }else if(ans[1]>ans[0]){
        cout<<(ans[1]-ans[0])/2<<endl;
        return;
    }else{
        int res = 0;

        res = loopit(arr, ans, 2*n, 1);
        cout<<res<<endl;
    }

 
}

int main(){

    vector<int> ans(2, 0);
    ans[1]++;
    ans[1]++;
    ans[0]++;
    ans[1]++;
    ans[0]++;
    cout<<ans[0]<<" "<<ans[1]<<endl;

    int t;
    // cin>>t;
    // while(t--){
    //     catc();
    // }

    return 0;

}