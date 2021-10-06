//problem statement(link) : https://practice.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1

#include <bits/stdc++.h>
using namespace std;
/* The function returns 1 if
IP string is valid else return 0
we are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            int dot=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='.'){
                    dot++;
                }
            }
            if(dot!=3)  return 0;

            stringstream ss(s);
            string tmp;
            
            while(getline(ss,tmp,'.')){
                if(tmp.size()>3 || tmp.size()==0){
                    return 0;
                }
                if(tmp.size()>1 && tmp[0]=='0'){
                    return 0;
                }
                int num=0;
                for(int i=0;i<tmp.size();i++){
                    if(tmp[i]>='0'&&tmp[i]<='9'){
                        num=num*10 + (tmp[i]-'0');
                    }
                    else{
                        return 0;
                    }
                }
                if(tmp.size()>1&&num==0)  return 0;
                if(num>=0 && num<=255){
                    continue;
                }
                else{
                    return 0;
                }
                
            }
            
            return 1;
            
        }
};

int main() {
    // code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
} 
