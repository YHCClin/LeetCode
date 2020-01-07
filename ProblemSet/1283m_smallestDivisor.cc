class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int L = 1;
        int R = 0;
        for(int i = 0;i < n;i++) if(R < nums[i]) R = nums[i];
        while(L < R)
        {
            int M = (L + R) >> 1;
            int sum = 0;
            for(int i = 0;i < n;i++) sum += ceil(1.0*nums[i]/M);
            if(sum <= threshold)
            {
                R = M;
            }
            else
                L = M + 1;
        }
        return R;
    }
};