#include <stdio.h>
#include <Windows.h>
#include <vector>
#define N 30
using namespace std;
vector<vector<char>> board(N,vector<char>(N,'O'));
int main()
{
    HANDLE hOutput;
    COORD coord={0,0};
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
 
    while (1)
    {
        for (auto i : board)
        {
            SetConsoleCursorPosition(hOutput, coord);
            for (auto j : i)
            {
                printf("%c",j);
            }
        }
    }
}
 