#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cmath>

typedef long long ll;

ll solve(ll num){
    ll ans = 0;
    return ans;
}

int count(ll num){
    int cnt = 0;
    while(num){
        cnt ++;
        num /= 10;
    }
    return cnt;
}

ll generate(int n){
    int ans = 0, q = 0;
    while(n--){
        ans += pow(10,q++);
    }
    return ans;
}

ll dp[100005];

ll dfs(int cur, int ans){
    if(cur == 0) return 0;
    if(cur == 11) return 2;
    
}

int main() {
    ll num;
    scanf("%lld", &num);
    printf("%lld\n", solve(num));
    return 0;
}