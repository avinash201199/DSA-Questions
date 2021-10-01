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
        stack <pair<char,int>> st;   	       				//declaring a stack pair to store characters of string and its index number
        string ans;           	      	     				// declaring string to store the output string
        for(int i=0; i<s.length(); i++){      				//traversing through each character of input string
            if(!st.empty() and st.top().first==s[i]){			//comparing first element of top of stack pair to the string character
                if(st.top().second<k-1)					//if the second element of stack pair is less than k-1, 
                    st.push({s[i], st.top().second+1});			//push it in the stack and increase second element of stack pair by 1
                else							//else
                    while(!st.empty() and st.top().first==s[i])		//stack.pop() until the stack.top() is equal to first element of stack pair 
                    st.pop();						//or until the list gets empty
            }
           else{							//else if the stack is empty or stack.top().first is not equal to string character
               st.push({s[i], 1});					//push it to the stack and give second element of stack as 1
        }
        }
       while(st.size()>0){						//Now that we have traversed the whole string, characters left in the stack comprise
               ans.push_back(st.top().first);				//of output string, hence pushing them into thr ans string
               st.pop();
       }
        reverse(ans.begin(), ans.end());				//reversing the ans string
        return ans;							//returning ans
    }
