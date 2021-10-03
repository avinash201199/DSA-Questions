                    /* Given an unsorted integer array nums,
                  return the smallest missing positive integer.*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
          /*Solution implemented in O(n)*/
int firstMissingPositive(vector<int>& nums) {
        /*********OPTIMIZED APPROACH**********/
        bool one_is_present=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                one_is_present=true;
            if(nums[i]<1 or nums[i]>nums.size())
                nums[i]=1;
        }
        if(one_is_present==false)return 1;
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i]);
            nums[index-1]=-(abs(nums[index-1]));
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)return i+1;
        }
        return nums.size()+1;
}

int main(){
  int n;
  cout<<"Enter size of array : ";
  cin>>n;
  vector<int>nums;
  cout<<"Enter elements of array : ";
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    nums.push_back(x);
  }
  int ans=firstMissingPositive(nums);
  cout<<"First Missing Positive From array is : "<<ans;
}
