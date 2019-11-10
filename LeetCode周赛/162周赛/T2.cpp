#include "Include_all.h"

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int u = upper, l = lower;
        vector<vector<int>> res(2,vector<int>(colsum.size(),0));
        for(int i = 0;i < colsum.size();i++)
        {
            if(colsum[i] == 2)
            {
                res[0][i] = res[1][i] = 1;
                upper--;
                lower--;
            }
            else if(colsum[i] == 1)
            {
                if(upper >= lower)
                {
                    res[0][i] = 1;
                    upper--;
                }
                else
                {
                    res[1][i] = 1;
                    lower--;
                }
            }
        }
        int _upper = 0, _lower = 0;
        for(int i = 0;i < colsum.size();i++)
        {
            _upper+=res[0][i];
            _lower+=res[1][i];
        }
        if(_upper == u && _lower == l) return res;
        return vector<vector<int>>{};
    }
};