class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        for(size_t i = 0;  i < s.size(); i++) freq[s[i]]++;

        bool oddFreq = false;
        int ans = 0, maxOdd = 0;
        for(auto& [ _ , f ]: freq) {
            if(f%2==0) ans+=f;
            else {
                ans += f - 1;
                oddFreq = true;
            }
        }

        return ans + oddFreq;
    }
};
