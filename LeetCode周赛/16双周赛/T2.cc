#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findBestValue(vector<int>& arr, int target) {
        int sum = 0, n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> ar(n,0);
        ar[0] = arr[0];
        for(int i = 1;i < n;i++)
            ar[i] = arr[i] + ar[i-1];
        int ans = target/n-10;
        int preDiff = INT_MAX;
        int curDiff = INT_MAX;
        int minDiff = INT_MAX;
        int bestAns;
        int flag = true;
        while(flag)
        {
        	int i;
            for(i = 0;i < n;i++)
            {
                if(arr[i] > ans) { sum = (ar[i-1] + ans * (n-i)); break;}
            }
            if(i >= n) sum = ar[n-1];
            cout << sum << endl;
            curDiff = abs(sum - target);
            if(minDiff > curDiff){minDiff = curDiff;bestAns = ans;ans++;}
           	else
           	{
           		return bestAns;
           	}
        }
        return ans;
}

int main()
{
	vector<int> arr = {60864,25176,27249,21296,20204};
	cout << findBestValue(arr,56803) << endl;
}