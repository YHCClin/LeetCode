/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 */

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if(n % W != 0) return false;
        map<int,int> mp;
        for(auto &i : hand) mp[i]++;
        for(auto iter = mp.begin();iter != mp.end();){
            while(iter!=mp.end() && iter->second <= 0) iter++;
            if(iter == mp.end()) break;
            int cm = iter->first,cnt = 0;
            for(cnt = 0;cnt < W;++cnt) {
                if(mp[cm] > 0){
                    mp[cm]--;
                    cm++;
                }
                else return false;
            }
        }
        return true;
    }
};
// @lc code=end

