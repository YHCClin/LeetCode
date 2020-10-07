#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

inline int count(ll num){
    return floor(log10((double)num))+1;
}

bool allOne(ll num){
    while(num){
        if(num%10 != 1)
            return false;
        num /= 10;
    }
    return true;
}

ll generate(int n){
    int ans = 0;
    while(n--){
        ans = ans * 10 + 1;
    }
    return ans;
}

ll dfs(ll cur){
    if(cur == 0) return 0;
    if(allOne(abs(cur))) return count(abs(cur));
    else{
        int cnt = count(abs(cur));
        ll gn = generate(cnt);
        ll gnn = generate(cnt+1);
        return abs(abs(cur)-gn) < abs(abs(cur)-gnn) ? cnt+dfs(abs(cur)-gn) : cnt+1+dfs(abs(cur)-gnn);
    }
}


int main() {
    
    ll num = 0;
    scanf("%lld", &num);
    printf("%lld\n", dfs(num));
    return 0;
}
