#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        if(n == 0) return 0;
        if(s == t) return 0;
        map<char, int> maps;
        for(int i = 0;i < 26;i++) maps['a'+i] = 0;
        for(int i = 0;i < n;i++)
        {
            maps[s[i]]++;
        }
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            if(maps[t[i]]>0) maps[t[i]]--;
            else
            {
                ans++;
            }
        }
        return ans;
    }
};