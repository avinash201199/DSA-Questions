class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            
        int size1 = nums1.size();
        int size2 = nums2.size();

        vector<int> temp(size1+size2);

        int s1=0,s2=0,k=0;
        
        while (s1<size1 && s2<size2){
            if(nums1[s1]<nums2[s2]){
                temp[k++] = nums1[s1++];
            }else if(nums1[s1]>nums2[s2]){
                temp[k++] = nums2[s2++];
            }
            else{
                temp[k++] = nums1[s1++];
                temp[k++] = nums2[s2++];
            }
        }
        
        while(s1<size1){
            temp[k++] = nums1[s1++];
        }
        while(s2<size2){
            temp[k++] = nums2[s2++];
        }
        
        int tempSize = size1+size2;
        if(tempSize%2 == 0){
            return (double)(temp[tempSize/2]+temp[tempSize/2 - 1])/2;
        }else{
            return (double)temp[tempSize/2];
        }
    }
};
