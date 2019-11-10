#include "Include_all.h"
using namespace std;

int cnt[100], cnt2[100];
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        memset(cnt, 0, sizeof(cnt)) ;
        for (char c: letters) ++cnt[c - 'a'];
        int lim = (1 << n);
        int ans = 0;
        for (int i = 0; i < lim; ++i){
            for (int j = 0; j < 26; ++j)
                cnt2[j]  = 0;
            for (int j = 1, t = 0; t < n; ++t, j <<= 1){
                if (!(j & i)) continue;
                for (char cc: words[t])
                    ++cnt2[cc - 'a'];
            }
            bool flag = true;
            int tot = 0;
            for (int j = 0; j < 26; ++j){
                if (cnt2[j] > cnt[j]){
                    flag = false;
                    break;
                }
                tot += cnt2[j] * score[j];
            }
            if (flag) ans = max(ans, tot);
        }
        return ans;
    }
};

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,pair<int,int>> dic_;
        for(auto c : letters)
        {
            dic_[c].first++;
            dic_[c].second = score[c - 'a'];
        }
        int res = 0;
        int max = 0;
        for(int i = 0;i < words.size();i++)
        {
            unordered_map<char,pair<int,int>> dic(dic_);
            res=0;
            for(int j = i;j < words.size();j++)
            {
                unordered_map<char,int> word;
                for(auto c : words[j])
                {
                    word[c]++;
                }
                bool flag = true;
                for(auto it = word.begin();it != word.end();it++)
                {
                    if(it->second > dic[it->first].first) flag = false;
                }
                if(flag)
                {
                    for(auto it = word.begin();it != word.end();it++)
                    {
                        dic[it->first].first -= it->second;
                        res += dic[it->first].second * it->second;
                        if(res > max)
                            max = res;
                    }
                }
            }
        }
        
        return max;
    }
};