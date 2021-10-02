#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long int
using namespace std;
int main()
{   int t; 
     cin>>t;
    while(t--)
    {
        ll numberofstalls,numberofcows;
        cin>>numberofstalls>>numberofcows;
        vector<ll> stalls;

        for(ll i=0;i<numberofstalls;++i)
        {
            ll p;
            cin>>p;
            stalls.push_back(p);
        }

       sort(stalls.begin(),stalls.end());

       ll end=stalls[numberofstalls-1]-stalls[0];
       ll start=0;
       ll answer=0;

       while(start<=end)
       {
           ll mid=(start+end)/2;
           bool cowcanbekept=checkcow(stalls,numberofcows,numberofstalls,mid);
       if(cowscanbekept==true)//If cows have been placed correctly  
       {
           answer=mid;
           start=mid+1;
       }
       else{
           end=mid-1;
          }
       }
       cout<<answer<<'\n';
    }
    return 0;
}
