#include "Include_all.h"
using namespace std;

class Solution {
public:
    // 单排的四种空座位状态
    int cm = 0b0001111000;
    int cl = 0b0111100000;
    int cr = 0b0000011110;
    int ca = 0b0111111110;
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 0;
        unordered_map<int,int> sits; //sits[i] 表示第 i 排座位的状态位图
        for(auto &v : reservedSeats) sits[v[0]] |= (1 << (v[1]-1));// 为 1 表示已被占
        ans = (n - sits.size()) * 2;// 整排全部空着的座位可以坐两家
        for(const auto &cur : sits) {// 逐排判断
            if((cur.second & ca) == 0) {ans += 2; continue;}
            if((cur.second & cr) == 0) {ans += 1; continue;}
            if((cur.second & cl) == 0) {ans += 1; continue;}
            if((cur.second & cm) == 0) {ans += 1; continue;}
        }
        return ans;
    }
};