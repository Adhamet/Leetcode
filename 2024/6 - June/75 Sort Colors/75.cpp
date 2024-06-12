class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zc=0,oc=0,tc=0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]==0) zc++;
            else if(nums[i]==1) oc++;
            else tc++;
        }

        int itr = 0;
        for(int i = 0; i < zc; i++) nums[itr++]=0;
        for(int i = 0; i < oc; i++) nums[itr++]=1;
        for(int i = 0; i < tc; i++) nums[itr++]=2;
    }
};
