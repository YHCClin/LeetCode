#include <bits/stdc++.h>
using namespace std;

void buildST(int left, int right, int p, vector<int>& D, vector<int> & a)
{
    if(left == right)
    {
        D[p] = a[left];
        return;
    }
    int mid = left + (right - left)/2;
    buildST(left, mid, p*2, D, a);
    buildST(mid+1, right, p*2+1, D, a);
    D[p] = D[p * 2] + D[p * 2 + 1];
}

int getSum(int left, int right, int cl, int cr, int p, vector<int> &D)
{
	if(left <= cl && cr <= right)
		return D[p];
	int mid = cl + (cr - cl)/2, sum = 0;
	if(left <= mid)
		sum += getSum(left, right, cl, mid, p * 2, D);
	if(right > mid)
		sum += getSum(left, right, mid+1, cr, p * 2 + 1, D);
	return sum;
}

void updateST(int cl, int cr, int index, int val, int p, vector<int>& D,vector<int>& a)
{
	if(cl == cr)
	{
		a[index] = val;
		D[p] = val;
		return;
	}
	else
	{
		int mid = cl + (cr - cl)/2;
		if(index >= cl && index <= mid)
			updateST(cl, mid, index, val, p * 2, D, a);
		else if(index > mid && index <= cr)
			updateST(mid + 1, cr, index, val, p * 2 + 1, D, a);
		D[p] = D[p * 2] + D[p * 2 + 1];
	}
}

int main()
{
	vector<int> D(10,0);
	vector<int> a(6);
	for(int i = 0; i < a.size();i++)
		a[i] = i;

	cout << "Building STree:" << endl;
	buildST(1, 5, 1, D, a);
	cout << "STree:";
	for(int i = 1;i < D.size();i++)
		cout << D[i] << " ";
	cout << endl;
	cout << "================================" << endl;
	cout << "Quary:(1,3)"<< endl;
	cout << getSum(1,3,1,5,1,D) << endl;
	cout << "================================" << endl;
	cout << "Update: a[1] = 6" << endl;
	updateST(1,5,1,6,1,D,a);
	cout << "STree:";
	for(int i = 1;i < D.size();i++)
		cout << D[i] << " ";
	cout << endl;
	cout << "================================" << endl;
	cout << "Quary:(1,3)"<< endl;
	cout << getSum(1,3,1,5,1,D) << endl;

}