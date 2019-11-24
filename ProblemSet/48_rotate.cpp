#include "Include_all.h"
using namespace std;


//先转置，再换列
void rotate(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	int i,j,temp;
	for(i = 0;i < n;++i)
	{
		for(j = i;j < n;++j)
		{
			if(i != j)
			{
				temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
	}
	for(i = 0;i < n;++i)
	{
		for(int a = 0,b = n-1;a < b;++a,--b)
		{
			temp = matrix[i][a];
			matrix[i][a] = matrix[i][b];
			matrix[i][b] = temp;
		}
	}
}

//另解。。。

int main()
{
	vector<vector<int>> matrix{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
	for(auto i : matrix)
	{
		for(auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	rotate(matrix);
	for(auto i : matrix)
	{
		for(auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}