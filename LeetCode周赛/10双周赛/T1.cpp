#include "Include_all.h"
using namespace std;

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int i = 0,j = 0,k = 0;
        int n = arr1.size();
        vector<int> res;
        while(i < n && j < n && k < n)
        {
            if(arr1[i]==arr2[j] && arr2[j]==arr3[k])
            {
                res.push_back(arr1[i]);
                i++;j++;k++;
            }
            else
            {
                int Max = max(max(arr1[i],arr2[j]),arr3[k]);
                while(i < n && arr1[i]<Max) i++;
                while(j < n && arr2[j]<Max) j++;
                while(k < n && arr3[k]<Max) k++;
            }
        }
        return res;
    }
};