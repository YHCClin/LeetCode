#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


string findSmallestRegion(vector<vector<string>>& regions, string reg1,string reg2)
{
	unordered_map<string,string> ParentOf;
	for(auto regList : regions)
	{
		string regHead = regList[0];
		for(int i = 1;i < regList.size();i++)
		{
			ParentOf[regList[i]] = regHead;
		}
	}
	// find region12's Father
	vector<string> ParentOfReg1;
	ParentOfReg1.push_back(reg1);
	while(ParentOf.find(reg1)!=ParentOf.end())
	{
		ParentOfReg1.push_back(ParentOf[reg1]);
		reg1 = ParentOf[reg1];
	}
	vector<string> ParentOfReg2;
	ParentOfReg2.push_back(reg2);
	while(ParentOf.find(reg2)!=ParentOf.end())
	{
		ParentOfReg2.push_back(ParentOf[reg2]);
		reg2 = ParentOf[reg2];
	}
	// find public father
	for(int i = 0;i < ParentOfReg1.size();i++)
	{
		for(int j = 0;j < ParentOfReg2.size();j++)
		{
			if(ParentOfReg1[i] == ParentOfReg2[j])
			{
				return ParentOfReg1[i];
			}
		}
	}
	return "";
}

int main()
{
	vector<vector<string>> regions = {{"Earth","North America","South America"},
										{"North America","United States","Canada"},
										{"United States","New York","Boston"},
										{"Canada","Ontario","Quebec"},
										{"South America","Brazil"}};
	vector<vector<string>> regions_ = {{"Earth", "North America", "South America"},{"North America", "United States", "Canada"},{"United States", "New York", "Boston"},{"Canada", "Ontario", "Quebec"},{"South America", "Brazil"}};
	string region1 = "South America";
	string region2 = "North America";
	cout << findSmallestRegion(regions,region1,region2) << endl;
	return 0;
}