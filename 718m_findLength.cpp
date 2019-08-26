#include "Include_all.h"
using namespace std;

//暴力双指针法
int findLength(vector<int>& A,vector<int>& B)
{
	int a = 0,b = 0;
	int length,max_len=0;
	while(a < A.size())
	{
		int i = a;
		length = 0;
		while( b < B.size() && i < A.size())
		{
			if(A[i] == B[b])
			{
				length++;
				
				i++;
				b++;
			}
			else
			{
				if(length > max_len)
					max_len = length;
				length=0;
				
				b++;
			}
		}
		a++;
	}
	return max_len;

}

int main()
{
	vector<int> A{1,2,3,2,1};
	vector<int> B{3,2,1,4,7};
	cout << findLength(A,B) << endl;
	return 0;
}