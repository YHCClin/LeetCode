#include <iostream>
#include <vector>
#define maxn 50
using namespace std;

void _zero(int G[][])
{
	memset(G, 0, sizeof(G));
}

class BPM {
public:
	int n, m, G[maxn][maxn];
	int left[maxn];
	bool T[maxn];

	void init(int n, int m) {this-> n = n; this-> m = m; _zero(G);}

	bool match(int u)
	{
		for(int v = 0; v < m; v++)
		{
			if(G[u][v] && !T[v])
			{
				T[v] = true;
				if(left[v] == -1 || match())
			}
		}
	}
}

void maxMatch()
{

}

int main()
{

	return 0;
}