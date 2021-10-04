/*Q)Given n non-negative integers representing an elevation
 map where the width of each bar is 1, compute how much water
 it can trap after raining.
*/
#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) 
{
    if(height.size()<=2)
        return 0;
    int l[height.size()];
    int r[height.size()];
    l[0]=height[0],r[height.size()-1]=height[height.size()-1];
    for(int i=1;i<height.size();i++)
        l[i]=max(height[i],l[i-1]);
    for(int i=height.size()-2;i>=0;i--)
        r[i]=max(height[i],r[i+1]);
    int maxi=0;
    for(int i=0;i<height.size();i++)
        maxi+=(min(r[i],l[i])-height[i]);
    return maxi;
}
int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//code goes here
    // let use consider an example testcase
    vector<int>height = {4,2,0,3,2,5};
    cout <<trap(height)<<endl;

return 0;
}