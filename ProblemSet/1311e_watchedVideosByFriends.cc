#include "Include_all.h"

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<bool> visited(n,false);
        // 建图
        vector<vector<int>> Mg(n,vector<int>(n,0));
        for(int i = 0;i < n;i++)
        {
            for(auto j : friends[i])
            {
                Mg[i][j] = 1;
                Mg[j][i] = 1;
            }
        }

        queue<int> que; // 遍历队列
        que.push(id);
        visited[id] = true;
        vector<int> level_friends;
        int cur_level = 0;
        while(!que.empty())
        {
            int size = que.size();
            
            if(cur_level == level)
            {
                while(!que.empty())
                {
                    level_friends.push_back(que.front());
                    que.pop();
                }
                break;
            }
            
            for(int j = 0;j < size;j++)
            {
                int cur = que.front();
                que.pop();
                for(int i = 0;i < n;i++)
                {
                    if(i != cur && Mg[cur][i] && !visited[i])
                    {
                        que.push(i);
                        visited[i] = true;
                    }
                }
            }
            cur_level++;
        }
        map<string,int> videos;
        for(auto i : level_friends)
        {
            for(auto j : watchedVideos[i])
            {
                videos[j]++;
            }
        }
        vector<string> ans;
        vector<pair<int,string>> vs;
        for(auto it = videos.begin();it != videos.end();it++)
        {
            vs.push_back(make_pair(it->second,it->first));
        }
        sort(vs.begin(),vs.end());
        for(auto i : vs)
            ans.push_back(i.second);
        return ans;
    }
};