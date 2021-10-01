#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

string removeDuplicates(string s, int k);

int main() {
    string s, ans;
    cin>>s;
    int k;
    cin>>k;
    ans=removeDuplicates(s,k);
    cout<<ans<<endl;
	return 0;
}

   string removeDuplicates(string s, int k) {
        stack <pair<char,int>> st;
        string ans;
        int count=0;
        for(int i=0; i<s.length(); i++){
            if(!st.empty() and st.top().first==s[i]){
                if(st.top().second<k-1)
                    st.push({s[i], st.top().second+1});
                else
                    while(!st.empty() and st.top().first==s[i])
                    st.pop();
            }
           else{
               st.push({s[i], 1});
        }
        }
       while(st.size()>0){
               ans.push_back(st.top().first);
               st.pop();
       }
        reverse(ans.begin(), ans.end());
        return ans;
    }