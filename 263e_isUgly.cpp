#include "Include_all.h"
using namespace std;

bool isUgly(int num)
{
	int temp = num;
	while(temp!=1)
	{
		if(temp%2==0) temp = temp/2;
		else if(temp%3==0) temp = temp/3;
		else if(temp%5==0) temp = temp/5;
		else
			break;
	}
	if(temp == 1) return true;
	else return false;

}
int nthUglyNumber(int n) {
        int count = 0;
        for(int i = 1;i < INT_MAX;i++)
        {
            if(isUgly(i))
            {
            	count++;
            	cout << i << endl;	
            }
            
            if(count==n) return i;
        }
        return 0;
    }

int main()
{
	cout << isUgly(8) << endl;
	cout << nthUglyNumber(100) << endl;
	return 0;
}