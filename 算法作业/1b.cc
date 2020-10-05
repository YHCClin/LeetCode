#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unordered_set>
using namespace std;

typedef long long LL;

bool judge(LL n){
    unordered_set<int> s;
    while(n){
        s.insert(n % 10);
        if(s.size() > 2) return false;
        n /= 10;
    }
    return true;
}

int main (){
    LL num, ans = 0;
    scanf("%lld", &num);
    for(int i = 1;i <= num;i++){
        if(judge(i)) ans++;
    }
    printf("%lld\n",ans);
}