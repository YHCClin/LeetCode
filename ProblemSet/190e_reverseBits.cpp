#include "Include_all.h"
using namespace std;

uint32_t anti_Binarilize(uint32_t n)
{
	uint32_t res = 0;
    string binaryStr = "";
    char bits[2] = {'0','1'};
    for(int i = 0;i < 32;i++)
    {
        binaryStr += bits[n>>i & 1];
    }
    cout << binaryStr << endl;
    for(int i = binaryStr.size()-1,j = 0;i >= 0;--i,j++)
    {
    	res += (binaryStr[i]-'0')*pow(2,j);
    }
    return res;
}
uint32_t reverseBits(uint32_t n) {
     return anti_Binarilize(n);
}

int main()
{
	uint32_t n = 43261596;
	cout << anti_Binarilize(n) << endl;
	return 0;
}