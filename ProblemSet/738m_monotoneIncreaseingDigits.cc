#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string dig = to_string(N);
        //reverse(dig.begin(),dig.end());
        int flag = dig.size();
        for(int i = dig.size()-1;i > 0;i--) {
            cout << i << endl;
            if(dig[i]<dig[i-1]) {
                dig[i-1]--;
                flag = i;
            }
        }
        for(int j = flag; flag < dig.size();++j) dig[flag]='9';
        return atoi(dig.c_str());
    }
};

int main(){
    Solution* s = new Solution();
    cout << s->monotoneIncreasingDigits(853567367) << endl;
    return 0;
}
