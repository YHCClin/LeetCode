#include <iostream>
#include <vector>
using namespace std;

    vector<int> plusOne(vector<int>& digits) {
        int remain;
        for(int i = digits.size()-1;i >= 0;--i )
        {
            remain = (digits[i]+1)%10;
            if(remain == 0)
            {
                digits[i] = 0;
                if(i-1<0)
                {
                    digits.insert(digits.begin(),1);
                    return digits;
                }
            }
            else
            {
                digits[i]++;
                return digits;
            }
        }
        return digits;
    }


int main()
{
    std::vector<int> dig{9,9,9};
    plusOne(dig);
    for(auto i : dig)
    {
        cout << i;
    }
    cout << endl;
    return 0;
}