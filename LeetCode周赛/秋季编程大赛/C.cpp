#include "Include_all.h"
using namespace std;

bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
		//[u,v]为当前位置,[a,b]为第一轮指令执行后的位置
        int a=0,b=0,u=0,v=0;
        for(auto i:command)if(i=='R')a++;
        else b++;
        bool res=false;
        for(auto i:command)
        {
            for(auto j:obstacles)
            	//障碍物在终点前 && 以[u,v]为新原点，碰上障碍物
            	if(j[0]<=x && j[1]<=y && (j[0]-u)%a==0 && (j[1]-v)%b==0 && (j[0]-u)/a==(j[1]-v)/b)
            		return false;
            //目标点碰上碰上障碍物
            if((x-u)%a==0 && (y-v)%b==0 && (x-u)/a==(y-v)/b) res=true;
            //更新位置（原点）
            if(i=='R') u++;
            else v++;
        }
        return res;
}
//超时解法
bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
	int n = command.size();
	
	bool ext = !obstacles.empty();
	vector<int> beg = {0,0};
	while(1)
	{
		int i = 0;
		while(i < n)
		{
			if(command[i] == 'U') beg[0]++;
			else beg[1]++;
			if(beg[0]==x && beg[1]==y) return true;
			if(beg[0]>x || beg[1]>y) return false;
			if(ext && find(obstacles.begin(),obstacles.end(),beg) != obstacles.end())
				return false;
		}
	}
	return true;
}

int main()
{
	vector<vector<int>> obstacles = {{2,2}};
	string command = "URR";
	cout << robot(command,obstacles,3,2) << endl;
	return 0;
}