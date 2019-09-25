#include "Include_all.h"
using namespace std;
//遍历比较
int game(vector<int>& guess, vector<int>& answer) {
	int n = guess.size();
	int res = 0;
	for(int i = 0;i < n;++i)
	{
		if(guess[i] == answer[i])
			res++;
	}
	return res;
}

int main()
{
	vector<int> guess = {1,2,3};
	vector<int> answer = {3,2,1};
	cout << game(guess, answer) << endl;
	return 0;
}