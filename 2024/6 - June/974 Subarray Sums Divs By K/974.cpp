class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int,int> pre = { {0,1} };
        for(int num: nums) {
            sum = (sum + num) % k;
            if(sum<0) sum += k;
            if(pre.find(sum) != pre.end()) {
                ans += pre[sum];
                pre[sum]+=1;
            } else pre[sum]=1;
        }
        return ans;
    }
};
