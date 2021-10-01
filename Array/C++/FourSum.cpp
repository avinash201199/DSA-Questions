class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            int j=i+1;
            while(j<n)
            {
                int sum=target+(-1)*(nums[i]+nums[j]);
                int k=j+1;
                int l=n-1;
                while(k<l)
                {
                    if(nums[k]+nums[l]<sum)
                        k++;
                    else if(nums[k]+nums[l]>sum)
                        l--;
                    else
                    {
                        res.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1])
                        {
                            k++;
                        }
                        while(k<l && nums[l]==nums[l+1])
                            l--;
                    }
                }
                j++;
                while(j<n && nums[j]==nums[j-1])
                    j++;
            }
            i++;
                while(i<n && nums[i]==nums[i-1])
                    i++;
            
        }
        return res;
    }
};
