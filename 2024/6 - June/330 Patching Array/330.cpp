class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i=0,patches=0;
        long long sum = 1;
        while(sum<=n) {
            if(i<nums.size() && nums[i] <= sum) sum += nums[i++];
            else sum += sum, patches++;
        }
        return patches;
    }
};
