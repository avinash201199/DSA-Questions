/*
This problem has been taken from SPOJ.(Code has been written with explicit commenting.)
AGGRCOW - Aggressive cows 
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.

The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other 
once put into a stall. 
To prevent the cows from hurting each other, FJ wants to assign the cows 
to the stalls, such that the minimum distance between any two of them is as large as possible. 
What is the largest minimum distance?

Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
*/
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long int
using namespace std;
bool checkcow(vector<ll> &stalls,ll numberofcows,ll numberofstalls, ll min_distance)
{
ll recent_cow=stalls[0];//Assume that first value is the cow that has been chosen
ll counter=1;           //counter will be used to break the loop when all cows have been counted

   for(ll i=1;i<numberofstalls;++i)//Start loop from 1 as we have already chosen the cow at the 0th index 
   {
       if(stalls[i]-recent_cow>=min_distance)//If a distance larger than or equal to mid value is found
       {
           recent_cow=stalls[i];//Update mininum value  
            ++counter;
            if(counter==numberofcows)//check if all cows have been counted
            {
                return true;
            }
       }
   }
   return false;//If all cows have been placed correctly,return true else false
}
int main()
{   int t; 
     cin>>t;
    while(t--)
    {
        ll numberofstalls,numberofcows;
        cin>>numberofstalls>>numberofcows;
        vector<ll> stalls;//vector of stalls

        for(ll i=0;i<numberofstalls;++i)
        {
            ll p;
            cin>>p;
            stalls.push_back(p);//Binary Search can be applied on sorted vector 
        }

       sort(stalls.begin(),stalls.end());

       ll end=stalls[numberofstalls-1]-stalls[0];//end is the MAXIMUM DISTANCE we can get between sorted elements of stalls vector
       //(or the maximum possible search space for applying binarty search)
       ll start=0;//start variable 
       ll answer=0;//answer variable

       while(start<=end)
       {
           ll mid=(start+end)/2;//mid is the middle value of start,end
           bool cowcanbekept=checkcow(stalls,numberofcows,numberofstalls,mid);//returns true if all cows have been placed at
           //the best possible stalls
       if(cowcanbekept==true)//If cows have been placed correctly  
       {
           answer=mid;
           start=mid+1;//check the values from mid+1 till end 
       }
       else{
           end=mid-1;//check the values from start till end
          }
       }
       cout<<answer<<'\n';
    }
    return 0;
}
