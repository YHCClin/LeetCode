#include <iostream>
#include <vector>

using namespace std;

// 实现差分数组类
class Difference {
    private:
        vector<int> diff;
    public:
        Difference(vector<int> &nums){
            diff = vector<int>(nums.size(),0);
            diff[0] = nums[0];
            for(int i = 1;i < nums.size();++i)
                diff[i] = nums[i] - nums[i - 1];
        }

    // 在区间[i,j]上加val
    void increment(int i, int j, int val){
        diff[i] += val;
        if(j + 1 < diff.size()){
            diff[j+1] -= val;
        }
    }

    // 根据差分数组构造结果数组
    vector<int> result() {
        vector<int> res(diff.size(),0);
        res[0] = diff[0];
        for(int i = 1;i < diff.size();++i){
            res[i] = res[i-1] + diff[i];
        }
        return res;
    }
};
// 差分数组
int main () {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    Difference diff = Difference(nums);
    diff.increment(1,4,1);
    nums = diff.result();
    for(int i : nums) cout << i <<" ";
    cout << endl;
    return 0;
}