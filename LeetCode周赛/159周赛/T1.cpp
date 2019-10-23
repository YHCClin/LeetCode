#include "Include_all.h"
using namespace std;

/*
	两点成线，确定斜率，遍历坐标出现斜率不同返回false
	注意斜率不存在的情况（即竖线），会出现除以0错误
 */

class Solution {
public:
    static bool byx(vector<int> &coord1, vector<int> &coord2)
    {
        return coord1[0] < coord2[0];
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n == 1 || n == 2) return true;
        sort(coordinates.begin(),coordinates.end(),byx);
        int diffx = (coordinates[1][0]-coordinates[0][0]);
        //竖线的处理
        if(diffx == 0)
        {
            for(int i = 2;i < n;i++)
            {
                if(coordinates[i][0] != coordinates[0][0])
                    return false;
            }
        }
        // 确定斜率
        double k = (coordinates[1][1]-coordinates[0][1])/diffx;
        // 遍历坐标
        for(int i = 2;i < n;i++)
        {
            if((double)(coordinates[i][1]-coordinates[0][1])/(coordinates[i][0]-coordinates[0][0])!=k)
            {
                return false;
            }
        }
        return true;
    }
};