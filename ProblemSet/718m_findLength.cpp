#include "Include_all.h"
using namespace std;

int* get_next(int* p, int size)
{
	int* next = (int*)malloc(sizeof(int) * size);
	next[0] = -1;
	for (int i = 0, j = -1; i < size;)
	{
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			if(i<size)next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
	return next;
}
int kmp_len(int* t, int size, int* p, int s,int *len)
{
	int* next = get_next(p, s);
	int i = 0, j = 0;
	for (; i < size && j < s;)
	{
		if (j == -1||t[i]==p[j])++i, ++j;
		else
		{
			if (j> * len)* len = j;
			j = next[j];
		}
	}
	free(next);
	if (j > * len)* len = j;
	if (j == s)
	{
		return i - j;
	}
	else
	{
		return -1;
	}
}
int findLength(vector<int>& A, int ASize, vector<int>& B, int BSize)
{

	if (ASize == 0 || BSize == 0)return 0;
	int res = 0;
	for (int i = 0; i < ASize-res; ++i)
	{
		kmp_len(B, BSize, A + i, ASize - i, &res);
	}

	return res;
}

int main()
{
	vector<int> A{1,2,3,2,1};
	vector<int> B{3,2,1,4,7};
	cout << findLength(A,B) << endl;
	return 0;
}