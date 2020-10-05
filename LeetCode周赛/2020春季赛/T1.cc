#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCount(vector<int>& coins) {
        int ans  = 0;
        for(int i : coins) {
            ans += ceil(i/2.0);
        }
        return ans;
    }
};