#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size())return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0,high=n1;
        while(low<=high){
            int cut1=(low+high)/2;
            int cut2=(n1+n2+1)/2-cut1;

            int left1= cut1==0?INT_MIN:nums1[cut1-1];
            int left2= cut2==0?INT_MIN:nums2[cut2-1];

            int right1= cut1==n1?INT_MAX:nums1[cut1];
            int right2= cut2==n2?INT_MAX:nums2[cut2];

            if(left1<=right2 and left2<=right1){
                if((n1+n2)%2==0)
                    return (max(left1,left2)+min(right1,right2))/2.0;
                else
                    return max(left1,left2);
            }
            else if(left1>right2){
                high=cut1-1;
            }
            else{
                low=cut1+1;
            }
        }
        return 1.1;
    }


int main(){
  int size1,size2;
  vector<int> nums1,nums2;
  cout<<"Enter size of first array :";
  cin>>size1;
  cout<<"Enter elements in sorted order :";
  for(int i=0;i<size1;i++){
    int x;
    cin>>x;
    nums1.push_back(x);
  }
  cout<<"Enter size of second array :";
  cin>>size2;
  cout<<"Enter elements in sorted order :";
  for(int i=0;i<size2;i++){
    int x;
    cin>>x;
    nums2.push_back(x);
  }
  double median=findMedianSortedArrays(nums1,nums2);
  cout<<median;
}
