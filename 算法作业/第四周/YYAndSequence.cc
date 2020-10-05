#include <iostream>
#include <math.h>

using namespace std;

long long prefix[31271];                    // 前缀和数组

void init() {
    int i,sum = 0, cur = 10, cnt = 1;       // cur 表示当前整数段为10^(i-1)~10^i,cnt 表示当前数位
    for(i = 1;i < 31271;++i){
        if(i < cur) {
            sum = sum + cnt;
        }
        else { 
            cur *= 10;                      // 到下一个整数段
            cnt++;                          // 更新数位
            sum = sum + cnt;
        }
        prefix[i] = prefix[i-1] + sum;
    }
    return;
}

/*
 * 找到第 k 位所在的段
 */
int findSeg(int k){
    int i;
    for(i = 1;i < 31271 && k > prefix[i];++i);
    return i-1;
}

int main() {
    long long q = 0;
    scanf("%lld", &q);
    init();                             // 初始化
    while(q--) {
        long long k;
        scanf("%lld", &k);
        int s = findSeg(k);             //检查在哪一段之前
        int pos=k-prefix[s],len=0,i;    // cnt 记录在该段的第几位
        for(i=1; len < pos; ++i)        //计算那一位是什么数(数值非字符)
        {
            len+=floor(log10((double)i))+1;// floor(log10(x))+1 得到x的位数
        }
        printf("%d\n",(i-1) / (int)pow(10.0, len-pos)%10);
    }
    return 0;
}