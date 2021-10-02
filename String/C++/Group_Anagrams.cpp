// Enter the number of strings: 10
// Enter the strings: bat tab mat tam cat tab act mat tam rat

// Group-1: bat tab tab 
// Group-2: cat act 
// Group-3: mat tam mat tam 
// Group-4: rat 

#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string,vector<string>>m;
        
        for(auto str:strs){
            string s=str;
            sort(s.begin(),s.end());
            m[s].push_back(str);            
        }
        for(auto v:m){
            ans.push_back(v.second);
        }
        return ans;
    }

int main()
{
    int n;
    cout<<"Enter the number of strings: ";
    cin>>n;
    
    vector<string>v(n);
    cout<<"Enter the strings: ";
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    auto ans = groupAnagrams(v);
    
    cout<<"\n";
    for(int i = 0; i<ans.size(); i++){
        cout<<"Group-"<<i+1<<": ";
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }cout<<"\n";
    }
}
