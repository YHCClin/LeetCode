#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr = {3,4,9};
	int n = arr.size();
	vector<int> ar(n+1,0);
	for(auto i : ar) cout << i << endl;
	for(int i = 1;i < n+1;i++)
		ar[i] = ar[i-1] + arr[i-1];
	for(auto i : ar) cout << i << endl;
}