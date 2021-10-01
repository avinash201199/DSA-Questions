#include <bits/stdc++.h>
using namespace std;
int lengthOfLastWord(string s) 
{
        
        int n=s.size();
        if(n==0) return 0;
        
        int start,end;
        
        start=0;
        while(start< n && s[start]==' ') start++;      //left trim
        
        end=n-1;
        while(end >=0 && s[end]==' ') end--;         //right trim
        
        if(start>end) return 0;
        
        int pos=end;
        while(pos>=start)
        {
            if(s[pos]==' ') return end-pos;
            else pos--;
        }
        
        return end-pos;
        
}
int main() 
{
    string s="Hello World";
    
    cout<<lengthOfLastWord(s)<<endl;
    
  return 0; 
}
