#include<bits/stdc++.h>
using namespace std;

bool balanced(string exp)
{
    stack<char>st;
    char x;

    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            st.push(exp[i]);
            continue;
        }

        if(st.empty())
        
            return false;
        

        switch (exp[i])
        {
            case ')':
            x=st.top();
            st.pop();

            if(x=='{' || x=='[')
               return false;
            break;

            case '}':
                x = st.top();
                st.pop();

                if (x == '(' || x == '[')
                    return false;
                break;

            case ']':
                x = st.top();
                st.pop();

                if (x == '{' || x == '(')
                    return false;
                break;
        }
    }
    return (st.empty());
}
int main()
{
    string exp="{()}[]";
    if(balanced(exp))
    {
        cout<<"Balanced"<<endl;
    }
    else
    {
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}
