#include "Include_all.h"
using namespace std;

// 回溯
class solution {
public:
    int maxlen = 0;
    bool alph[26] = {false};
    void DFS(vector<string>& arr,bool *flag,int len,int i)
    {
        if(i == arr.size()) return;
        cout << arr[i] << endl;
        flag[i] = true;
        len += arr[i].size();
        if(maxlen < len) maxlen = len;
        for(int j = 0;j < arr[i].size();j++)
        {
            alph[arr[i][j]-97] = true;
        }
        for(int k = 0;k < arr.size();k++)
        {
            if(!flag[k])
            {
                bool can = true;
                for(int h = 0;h < arr[k].size();h++)
                {
                    if(alph[arr[k][h]-97])
                    {
                        can = false;
                        break;
                    }
                }
                if(can)
                {
                    DFS(arr,flag,len,k);
                    flag[k] = false;
                    for(int m = 0;m < arr[k].size();m++)
                    {
                        alph[arr[k][m]-97] = false;
                    }
                }
            }
            
        }
    }
    int maxLength(vector<string>& arr) {
        bool flag[arr.size()] = {false};
        int len = 0;
        DFS(arr,flag,len,0);
        return maxlen;
    }
};

vector<bool> flag(26,false);
vector<bool> temp(26,false);
// 暴力枚举
class Solution {
public:
    inline bool isNew(string& str)
    {
        for(int i = 0;i < str.size();i++)
        {
            if(flag[str[i]-97])
                return false;
        }
        return true;
    }
    inline void setFlag(string &str)
    {
        for(int i = 0;i < str.size();i++)
            flag[str[i]-97] = true;
    }
    int maxLength(vector<string>& ar) {
        int maxlen = 0;
        int len = 0;
        vector<string> arr;
        for(int i = 0;i < ar.size();i++)
        {
            unordered_set<char> set;
            for(int j = 0;j < ar[i].size();j++)
                set.insert(ar[i][j]);
            if(set.size() == ar[i].size())
            {
                arr.push_back(ar[i]);
            }
        }
        if(arr.size()==0) return 0;
        for(int i = 0;i <arr.size();i++)
        {
            len = arr[i].size();
            if(len > maxlen) maxlen = len;
            setFlag(arr[i]);
            for(int j = 0;j < arr.size();j++)
            {
                if(j != i && isNew(arr[j]))
                {
                    len += arr[j].size();
                    if(len > maxlen) maxlen = len;
                    setFlag(arr[j]);
                }
            }
            flag = temp;
        }
        return maxlen;
    }
};
int main()
{
	Solution s;
	vector<string> arr = {"a", "b", "n"};
	cout << s.maxLength(arr) << endl;
	return 0;
}