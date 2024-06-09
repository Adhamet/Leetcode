class Solution {
public:
    int appendCharacters(string s, string t) {
        int f = 0, len = 0;
        while(f < s.length() && len < t.length()) {
            if(s[f] == t[len]) len++;
            f++;
        }
        return t.length() - len;
    }
};
