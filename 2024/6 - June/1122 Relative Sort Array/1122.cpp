class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> countMap;
        vector<int> rem, res;

        for(int i = 0; i < arr2.size(); i++) countMap[arr2[i]]=0;

        for(int i = 0; i < arr1.size(); i++) {
            if(countMap.find(arr1[i]) != countMap.end())
                countMap[arr1[i]]++;
            else rem.push_back(arr1[i]);
        }

        sort(rem.begin(), rem.end());
        for(int i = 0; i < arr2.size(); i++)
            for(int j = 0; j < countMap[arr2[i]]; j++)
                res.push_back(arr2[i]);
        
        for(int i = 0; i < rem.size(); i++) res.push_back(rem[i]);
        return res;
    }
};
