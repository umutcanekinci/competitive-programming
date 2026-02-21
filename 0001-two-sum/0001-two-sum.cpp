class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i=0; i < nums.size(); i++){
            for(int j=0; j < nums.size() - i - 1; j++){
                if(nums[i] + nums[i + j + 1] == target) {

                    return {i, i+ j + 1};
                }
            }
        }
        


        return {0, 0};

    }
};