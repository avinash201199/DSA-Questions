#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> getVal(int arr[], int n){

      unordered_set<int> s;
      vector<int> res;
      int a;

      for(int i = 0; i<7; i++){
       a = n - arr[i];

       if(s.find(a)!=s.end()){
             res.push_back(a);
             res.push_back(arr[i]);
             
             return res;
       }
      s.insert(arr[i]);

      }
}

int main(){
      int arr[] = {1,4,6,2,5,3,0};
      int n = 3;

      auto q = getVal(arr,n);

     for(auto l : q){
           cout<<l<<" ";
     }
}