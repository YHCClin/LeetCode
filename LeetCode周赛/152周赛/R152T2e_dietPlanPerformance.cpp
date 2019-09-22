#include "Include_all.h"
using namespace std;

int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
       int n = calories.size(),res = 0;
       vector<int> sumOfPref(n+1, 0);
       for(int i = 0;i < n;i++) 
       {
       		sumOfPref[i+1] = calories[i]+sumOfPref[i];
       }
       for(auto i : sumOfPref)
       {
       		cout << i << "  ";
       }
       cout << endl;
       for(int i = 0;i <= n-k;i++)
       {
       		if(sumOfPref[i+k] - sumOfPref[i] < lower) res--;
       		else if(sumOfPref[i+k] - sumOfPref[i] > upper) res++;
       }
       return res;
}

int main()
{
	vector<int> calories = {6,13,8,7,10,1,12,11};
	cout << dietPlanPerformance(calories,6,5,37) << endl;
	return 0;
}