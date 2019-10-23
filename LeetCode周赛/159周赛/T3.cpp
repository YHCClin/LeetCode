#include "Include_all.h"
using namespace std;

/*
	这道题题目翻译的不咋滴，题目意思是找到一个最短的字串，替换它使得整串平衡
	该字串可以位于串头，串尾，串中
	故用双指针先从左侧贪心扫描，再从右侧贪心扫描得到初始态并记录当前字串长度
	再依次回退（每次左移一单位）左指针，右指针贪心左移，每次都记录字串长度，直到左指针不能再退为止
	返回过程中最短的子串长度
 */
class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char,int> counter;
        counter['Q'] = 0;
        counter['W'] = 0;
        counter['E'] = 0;
        counter['R'] = 0;
        int res = 0;
        int ava = n / 4;
        int i = -1,j = n-1;
        // 找到初始状态
        // 左指针向右贪心
        while(i < n-1)
        {
            i++;
            counter[s[i]]++;
            if(counter[s[i]] > ava)
            {
                counter[s[i]]--;
                i--;
                break;
            }
        }
        // 右指针向左贪心
        while(counter[s[j]] < ava)
        {
            counter[s[j]]++;
            j--;
        }
        j++;
        res = max(res,i+1+n-j);

        //依次回退左指针
        while(i >= 0)
        {
            counter[s[i]]--;
            i--;
            
            j--;
            //右指针向左贪心
            while(i < j && counter[s[j]] < ava)
            {
                counter[s[j]]++;
                j--;
            }
            j++;
            res = max(res,i+1+n-j);
        }
        return n-res;
    }
};