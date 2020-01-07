class Solution {
public:
    int subtractProductAndSum(int n) {
        int multi = 1;
        int sum = 0;
        while(n)
        {
            int fn = n%10;
            sum += fn;
            multi *= fn;
            n /= 10;
        }
        return multi - sum;
    }
};