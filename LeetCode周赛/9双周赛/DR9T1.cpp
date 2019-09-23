#include "Include_all.h"
using namespace std;

/*5072. 最多可以买到的苹果数量*/

int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int sum = 0;
        int i = 0;
        for(;i < arr.size();++i)
        {
            sum+=arr[i];
            if(sum >= 5000)
                return i;
        }
        return i;
}





int main()
{
	vector<int> arr = {100,200,150,1000};
	cout << maxNumberOfApples(arr) << endl;
	return 0;
}