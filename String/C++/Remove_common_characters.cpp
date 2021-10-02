#include<bits/stdc++.h>
using namespace std;
 
int main(){
   
string s1 = "abdjkli";
string s2 = "bxcvjbe";

string s3="";
string s4="";


for(int i=0;i<s1.length();i++){
    for(int j=0;j<s2.length();j++){
        if(s1[i] == s2[j]){
           goto here;
        }
    }
    s3 = s3 + s1[i];   
    here:
        continue;
    
}

for(int i=0;i<s2.length();i++){
    for(int j=0;j<s1.length();j++){
        if(s2[i] == s1[j]){
           goto he;
        }
    }
    s4 = s4 + s2[i];   
    he:
        continue;
    
}

cout<<s3<<s4;
}