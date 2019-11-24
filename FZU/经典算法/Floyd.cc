#include <iostream>
#include <vector>
#define INF 0xff00
using namespace std;

vector<vector<int>> Floyd(vector<vector<int>> &Mg, vector<vector<int>>& path)
{
    int n = Mg.size();
    vector<vector<int>> Min(Mg);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            path[i][j] = -1;
        }
    }

    for(int k = 0;k < n; k++)
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(Min[i][j] > Min[i][k] + Min[k][j])
                {
                    Min[i][j] = Min[i][k] + Min[k][j];
                    path[i][j] = k;
                }
            }
        }
    return Min;
}

void Quary(int a, int b, vector<vector<int>> &path)
{
    int n = path.size();
    int i = a, j = b;
    cout << a << " -=> ";
    while(path[i][j] != -1)
    {
        i = path[i][j];
        cout << i <<" -=> ";
    }
    cout << b << endl;
}


int main()
{
    vector<vector<int>> Mg = {
        {0,  5, INF,  7},
        {INF,  0,  4, 2},
        {3,    3,  0, 2},
        {INF, INF, 1, 0}
    };
    vector<vector<int>> path = {
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1} 
    };
    vector<vector<int>> Min(Floyd(Mg, path));
    for(auto i : Min)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    int i,j;
    while(cin >> i >>j)
        Quary(i,j,path);
    return 0;
}
