#include "Include_all.h"
using namespace std;

/*
    各种排序算法的实现
 */
 
class Solution {
public:
    // 插入排序：(TL)
    void Insert(vector<int> &arr){
    	int n = arr.size();
    	for(int i = 1;i < n;++i)
    	{
    		for(int j=i; j > 0;--j)
    		{
    			if(arr[j] < arr[j-1])
    				swap(arr[j-1], arr[j]);
    			else
    				break;
    		}
    	}
    }

    // 折半插入排序
    void BinaryInsertSort(vector<int> &arr){

    }

    // 冒泡排序
    void BubbleSort(vector<int> &arr){
    	int n = arr.size();
    	for(int i = n;i >= 0;--i) // 控制边界
    	{
    		bool flag = true;
    		for(int j = 1;j < i;++j)
    		{
    			if(arr[j] < arr[j-1])
    			{
    				swap(arr[j],arr[j-1]);
    				flag = false;
    			}
    		}
    		if(flag) break;
    	}
    }
    
    // 希尔排序
    void ShellSort(vector<int> &arr){

    }

    //简单选择排序
    void SimpleSelectSort(vector<int> &arr){

    }

    // 快速排序
    void QuickSort(vector<int> &arr){

    }

    // 堆排序
    void HeapSort(vector<int> &arr){

    }

    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
    }
};

int main(){
	vector<int> nums = {5,2,3,1,6,1,3,7,9,2};
	Solution S;
	S.BubbleSort(nums);
	for(auto i : nums){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}