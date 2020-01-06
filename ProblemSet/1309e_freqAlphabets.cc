#include "Include_all.h"

/**
 * 逆序后遍历
 */
class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        map<string,string> M = {{"1","a"},{"2","b"},{"3","c"},{"4","d"},{"5","e"},{"6","f"},
                                {"7","g"},{"8","h"},{"9","i"},{"10","j"},{"11","k"},{"12","l"},
                                {"13","m"},{"14","n"},{"15","o"},{"16","p"},{"17","q"},{"18","r"},
                                {"19","s"},{"20","t"},{"21","u"},{"22","v"},{"23","w"},{"24","x"},
                                {"25","y"},{"26","z"}
                               };
        
        reverse(s.begin(),s.end());
        int n = s.size();
        for(int i = 0;i < n;)
        {
            string cur = "";
            if(s[i] == '#')
            {
                cur += s.substr(i+1,2);
                reverse(cur.begin(),cur.end());
                ans += M[cur];
                i+=3;
            }
            else
            {
                cur += s[i];
                ans += M[cur];
                i++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};