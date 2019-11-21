#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


vector<int> Intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int,bool> hashmap;
	unordered_set<int> result;
	vector<int> res;
	for(auto i : nums1) hashmap[i]=true;
	for(auto j : nums2) if(hashmap[j]) result.insert(j);
	for(auto k:result) res.push_back(k);
	return res;
}

int main()
{
	vector<int> A = {1,3,4,6,9,9};
	vector<int> B ={2,4,9,9,9,10,11};
	vector<int> res(Intersection(A,B));
	for(auto i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}