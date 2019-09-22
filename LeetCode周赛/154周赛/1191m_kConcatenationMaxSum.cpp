#include "Include_all.h"
using namespace std;

long long maxSubSum(vector<int> & arr)
{
        long long curr = 0;
        long long ans = 0;
        
        for(int i = 0; i < arr.size(); ++i){
            curr += arr[i];
            ans = max(ans,curr);
            if(curr < 0){
                curr = 0;
            }
        }
        
        return ans;
}
long long mod = 1e9 + 7;
int kConcatenationMaxSum(vector<int>& arr, int k)
{
	vector<int> arr2;
	for(auto i : arr) arr2.push_back(i);
	for(auto i : arr) arr2.push_back(i);
	long sum = 0;
	for(auto i : arr) sum+=i; 
	long long sum1 = subSum(arr);
	long long sum2 = subSum(arr2);
	if(k==1) return sum1;
	if(sum < 0) //arr全和小于零，因此最大和数组不可能横跨超过两个arr数组长度
		return max(sum1,sum2);
	else        //arr全和大于等于零
	{
		if(sum1 == sum2) //所有K个数组，或一（两）个arr
			return max((k*sum)%mod,sum1);
		else             //所有k个数组，或前k-2个连续arr加后一个arr2
			return max((k*sum)%mod,(sum2+(k-2)*sum)%mod);
	}
}

int main()
{
	vector<int> arr = {-1,-2};
	cout << subSum(arr) << endl;
	cout << kConcatenationMaxSum(arr,7) << endl;
	return 0;
}