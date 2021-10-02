#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long int
using namespace std;
bool checkcow(vector<ll> &stalls,ll numberofcows,ll numberofstalls, ll min_distance)
{
ll recent_cow=stalls[0];//Assume that first value is the cow that has been chosen
ll counter=1;           //counter will be used to break the loop when all cows have been counted
   for(ll i=1;i<numberofstalls;++i)
   {
       if(stalls[i]-recent_cow>=min_distance)
       {
           recent_cow=stalls[i];
            ++counter;
            if(counter==numberofcows)
            {
                return true;
            }
       }
   }
   return false;
}
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
       if(cowcanbekept==true)//If cows have been placed correctly  
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
