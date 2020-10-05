#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

// 存储行、列下标
vector<int> cols(1005);
vector<int> rows(1005);

// 初始化
void init(){
    for(int i = 0;i < 1005;++i){
        cols[i] = i;
        rows[i] = i;
    }
    return;
}

// 0, 1 操作只需交换下标即可
// 操作 0
void op0(int x, int y, vector<int> &rows){
    swap(rows[x-1],rows[y-1]);
    return;
}

// 操作 1
void op1(int x, int y, vector<int> &cols){
    swap(cols[x-1],cols[y-1]);
    return;
}

// 操作2
int get(int x, int y, vector<vector<int>> &mat){
    return mat[rows[x-1]][cols[y-1]];
}
int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    
    init();
    while(q--){
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        switch (op)
        {
        case 0:
            op0(x,y,rows);
            break;       
        case 1:
            op1(x,y,cols);
            break;
        case 2:
            printf("%d\n",get(x,y,mat));
        default:
            break;
        }
    }
}