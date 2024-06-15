class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int minIncs = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) if (nums[i] <= nums[i - 1]) {
            int inc = nums[i - 1] + 1 - nums[i];
            minIncs += inc;
            nums[i] = nums[i - 1] + 1;
        }
        return minIncs;
    }
};
