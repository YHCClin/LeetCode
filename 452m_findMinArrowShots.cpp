#include "Include_all.h"
using namespace std;

bool less_x(vector<int>& v1, vector<int>& v2)
{
	return v1[0] < v2[0];
}

int findMinArrowShots(vector<vector<int>>& points)
{
	sort(points.begin(),points.end(),less_x);
	int shot_end = points[0][1];
	int res = 1;
	for(int i = 1;i < points.size();i++)
	{
		if(shot_end < points[i][0])//没有交集
		{
			res++;
			shot_end = points[i][1];
			//shot_area[1] = points[i][1];
		}
		else
		{
			shot_end = min(shot_end, points[i][1]);
		}
	}
	return res;
}

int main()
{
	vector<vector<int>> points = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};//{{10,16}, {2,8}, {1,6}, {7,12}};
	int res = findMinArrowShots(points);
	for(auto i : points)
	{
		for(int j = 0;j < i.size();j++)
		{
			cout << i[j] << " ";
		}
		cout << endl;
	}
	cout << res << endl;
	return 0;
}