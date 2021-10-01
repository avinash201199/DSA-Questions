class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n < 4) {
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++) {
            for(int j = i + 1; j < n;j++) {
                int tempTarget = target - nums[i] - nums[j];
                int front = j + 1;
                int back = n - 1;
                while(front < back) {
                    int two_sum = nums[front] + nums[back];
                    if(two_sum < tempTarget) front++;
                    else if(two_sum > tempTarget) back--;
                    else {
                        vector<int> tempRes;
                        tempRes.push_back(nums[i]);
                        tempRes.push_back(nums[j]);
                        tempRes.push_back(nums[front]);
                        tempRes.push_back(nums[back]);
                        res.push_back(tempRes);
                        while(front < back && nums[front] == tempRes[2]) front++;
                        while(front < back && nums[back] == tempRes[3]) back--;
                    }
                }
                while(j + 1 < n && nums[j + 1] == nums[j]) j++;
            }
            while(i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};
