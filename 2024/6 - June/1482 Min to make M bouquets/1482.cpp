class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), l=0, r=1e9, ans=-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            int count = 0, j=0;
            for(int i = 0; i < n; i++) {
                if(bloomDay[i]<=mid) j++;
                else j=0;
                if(j==k) { j = 0; count++; }
            }

            if(count>=m) { ans=mid, r=mid-1; }
            else l=mid+1;
        }
        return ans;
    }
};
