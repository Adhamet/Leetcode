class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        map<int,int> cC;

        for(int card: hand) cC[card]++;

        while(!cC.empty()) {
            int startC = cC.begin()->first;

            for(int i = 0; i < groupSize; i++) {
                int currC = startC + i;
                if(cC.find(currC) == cC.end()) return false;

                cC[currC]--;
                if(cC[currC] == 0) cC.erase(currC);
            }
        }

        return true;
    }
};
