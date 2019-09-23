#include "Include_all.h"
using namespace std;

/* 5071 找出所有行中最小公共元素 */

int smallestCommonElement(vector<vector<int>>& mat)
{
	int m = mat.size();
	int n = mat[0].size();
	int cur;
	for(int i = 0;i < n;i++)
	{
		cur = mat[0][i];
		int ext = 0;
		for(int j = 1;j < m;j++)
		{
			bool flag = false;
			int len = mat[j].size();
			for(int k = 0;k < len;k++)
			{
				if(mat[j][k] == cur)
				{
					ext++;
					break;
				}
				else if(mat[j][k] > cur)
				{
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		if(ext == m-1) return cur;
	}
	return -1;
}

int main()
{
	vector<vector<int>> mat = {{1,2,3,4,5},{2,4,5,8,10},{3,4,5,7,9,11},{1,3,4,5,7,9}};
	cout << smallestCommonElement(mat) << endl;
	return 0;
}