// Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color.  

#include <iostream>
using namespace std;

int solve(int a, int b)
{
    if(a == 1) return b;
  
    int same = b;        // same color fences 'ii'
    int diff = b * (b-1);       // different color fences 'ij'
    int total = same + diff;       // total 'ii'+'ij'
    
    for(int i = 3;i <= a;i++){
        same = diff;
        diff = total * (b - 1);
        total = same + diff;
    }
    return total; }
int main()
{
    int a,b;
    cout<<"Enter a and b =  "; // a = no of fences, b = no of colors
    cin>>a>>b;
  
    cout<<"Number of ways of painting the fence with atmost 2 having same color are " <<solve(a,b);
    return 0;   }
