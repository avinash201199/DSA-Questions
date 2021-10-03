class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int size = nums.size(),j,k;
        long int sum;
        
        set<vector<int>> temp_result;
        vector <int> temp(3);
        
        for(int i=0;i<size-2;i++){
            j=i+1;
            k= size - 1;
            while(j<k){
                sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    temp[0]=nums[i];
                    temp[1]=nums[j];
                    temp[2]=nums[k];
                    temp_result.insert(temp);
                    j++;
                    k--;
                }
                else if(sum<0){
                    j++;
                }else if(sum>0){
                    k--;
                }
            }
        }
        vector <vector<int>> result(temp_result.begin(),temp_result.end());
        return result;
    }
};
