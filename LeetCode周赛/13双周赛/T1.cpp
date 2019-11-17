#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string encode(int num) {
        if(num==0)return "";
        if(num==1)return "0";
        int n = num+1;
        string res="";
        bool flag=false;
        for(int i=31;i>=0;i--)
        {
            if(n&(1<<i) && !flag) {flag=true;continue;}
            if(flag){
                res+=((n&(1<<i)) ? "1" : "0");
            }
        }
        return res;
    }
};

int main()
{
	Solution S;
	cout << S.encode(388) << endl; // 10000101
	return 0;
}