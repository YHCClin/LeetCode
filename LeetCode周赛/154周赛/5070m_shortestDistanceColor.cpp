#include "Include_all.h"
using namespace std;
vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> next(3, vector<int>(n, -1)), prev(3, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            if (i) {
                for (int j = 0; j < 3; j++)
                    prev[j][i] = prev[j][i - 1];
            }
            prev[colors[i] - 1][i] = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n) {
                for (int j = 0; j < 3; j++) {
                    next[j][i] = next[j][i + 1];
                }
            }
            next[colors[i] - 1][i] = i;
        }
        vector<int> result;
        for (int i = 0; i < queries.size(); i++) {
            int ind = queries[i][0];
            int c = queries[i][1];
            int L, R;
            if (prev[c - 1][ind] == -1) L = (int)1e9;
            else L = ind - prev[c - 1][ind];
            if (next[c - 1][ind] == -1) R = (int)1e9;
            else R = next[c - 1][ind] - ind;
            if (min(L, R) == (int)1e9) result.push_back(-1);
            else result.push_back(min(L, R));
        }
        return result;
    }
vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries)
{
	
}


int main()
{

	return 0;
}