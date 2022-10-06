#include<bits/stdc++.h>
using namespace std;

int main(){

    int k;
    cin>>k;
    int **arr = new int*[k];
    int t= 0, count=0;;
    while(t<k){
        int n;
        cin>>n;
        arr[t]= new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[t][i];
            count++;
        }
        t++;
    }
    t=0;

    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> p;
    unordered_map<int, bool> map;

    while(t<k){
        p.push(arr[t][0]);
        map[arr[t][0]]=true;
        t++;
    }
    int nxtIndex=0;
    while(!p.empty()){
        v.push_back(p.top());
        t=0;
        while(t<k){
            if(arr[t][0]==p.top()){
                
            }
            if(map.count(arr[t][0])==0){
                map[arr[t][1]]=true;
                v.push_back(arr[t][0]);
                break;
            }
            t++;
        }

        
    }



    return 0;

}