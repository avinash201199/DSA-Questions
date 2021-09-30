class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0,ms=INT_MIN;
        for(int i=0;i<nums.size();i++){
            cs += nums[i];           
            ms = max(ms,cs);
            if(cs<0){
                cs=0;
            }
        }
        return ms;
    }
};
