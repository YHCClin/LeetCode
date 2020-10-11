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

<<<<<<< HEAD
ll dfs(int cur){
    if(cur == 0) return 0;
    if(allOne(abs(cur))) return count(abs(cur));
    else{
    	cur = abs(cur);
        int cnt = count(abs(cur));
        ll gn = generate(cnt);
        ll gnn = generate(cnt+1);
        return abs(cur-gn) < abs(cur-gnn) ? cnt+dfs(cur-gn) : cnt+1+dfs(cur-gnn);
=======
ll dfs(ll cur){
    if(cur == 0) return 0;
    if(allOne(abs(cur))) return count(abs(cur));
    else{
        int cnt = count(abs(cur));
        ll gn = generate(cnt);
        ll gnn = generate(cnt+1);
        return abs(abs(cur)-gn) < abs(abs(cur)-gnn) ? cnt+dfs(abs(cur)-gn) : cnt+1+dfs(abs(cur)-gnn);
>>>>>>> 7169be720449e9fde61a072525b06a0357a54bf8
    }
}


int main() {
    
    ll num = 0;
<<<<<<< HEAD
    while(1){
        scanf("%lld", &num);
        printf("%lld\n", dfs(num));
    }
=======
    scanf("%lld", &num);
    printf("%lld\n", dfs(num));
>>>>>>> 7169be720449e9fde61a072525b06a0357a54bf8
    return 0;
}
