/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool binaryserch(vector<int> &v,int target)
    {
        int n = v.size();
        int left = 0,right = n-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(v[mid]==target) return true;
            else if(v[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        int row;
        for(int r = 0;r < m; ++r)
        {
            if(target>=matrix[r][0] && target<=matrix[r][n-1])
            {
                return binaryserch(matrix[r],target);
            }
        }
        return false;
    }
};
// @lc code=end

