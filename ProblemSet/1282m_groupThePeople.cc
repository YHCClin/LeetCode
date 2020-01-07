class Solution {
public:
    // 将位于相同大小用户组的用户集合起来，再再集合中划分组
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        map<int,vector<int>> Map;
        for(int i = 0;i < n;i++)
        {
            Map[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(auto iter= Map.begin();iter != Map.end();iter++)
        {
            int cur_gs = iter->first;
            for(int i = 0;i < iter->second.size();)
            {
                vector<int> group;
                int j;
                for(j = i;j < i+cur_gs;j++)
                {
                    group.push_back(iter->second[j]);
                }
                res.push_back(group);
                i = j;
            }
        }
        return res;
    }
};