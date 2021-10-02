#include<bits/stdc++.h>
using namespace std;

int evaluatePostfix(string str)
    {
        int n=str.length();
        stack <int> s;
        for(int i=0;i<n;i++)
        {
            if(str[i]>='0' && str[i]<='9')
            s.push(str[i]-'0');
            
            else
            {
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                
                    if(str[i]== '+')
                    s.push(op1+op2);
                    
                    if(str[i]== '-')
                    s.push(op1-op2);
                   
                    if(str[i]== '*')
                    s.push(op1*op2);
                    
                    if(str[i]== '/')
                    s.push(op1/op2);    
            }
        }
        return s.top();
    }

int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
    cout<<evaluatePostfix(S)<<endl;
    }
    return 0;
}
