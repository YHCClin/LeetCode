#include <iostream>
#include <vector>
using namespace std;
// 区间覆盖问题，贪心法
class Solution {
    using Line = pair<int, int>;// 灌溉区间

public:
    int minTaps(int n, vector<int> ranges) {
        vector<Line> lines;
        for(size_t i=0;i<ranges.size();i++){ // 计算各水龙头的灌溉区间
            lines.emplace_back(i-ranges[i], i+ranges[i]);
        }

        int tail = 0, head = 0;// 已经覆盖的区间的左右端点值
        int line_count = 0;// 打开的水龙头数量

        while(tail < n){ // 如果还未覆盖所有花盆，循环执行
            tail = find(lines, head); // 选取剩余区间中左端点小于head的区间中右端点最大的区间
            if(head == tail){
                return -1;
            }
            head = tail; // 将选取的区间的末尾当做新的未覆盖区间
            line_count++;// 区间数加1
        }
        return line_count;
    }

    int find(vector<Line> &lines, int head){
        int tail = head;
        for(Line &line: lines){
            if(line.first<=head){
                tail = max(line.second, tail);
            }
        }
        return tail;
    }
}; 














bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] != b[0]) return a[0]<b[0];
    else return a[1] > b[1];
  }
  
class Solution {
public:
  int minTaps(int n, vector<int> &ranges){
    // 计算区间
    vector<vector<int>> ras;
    for(int i = 0;i < n+1; ++i){
      vector<int> ra = {i-ranges[i]>0 ? i-ranges[i] : 0, i+ranges[i]};
        if(ra[0]!=ra[1]) ras.push_back(ra);
    }
     if(ras.size() == 0) return -1;
    sort(ras.begin(),ras.end(),cmp);
    
    //选择区间
    int s = 0; // 已覆盖区域
    int ans = 1;
    int currange = 0;// 当前区间
    s = ras[0][1];// 先选第一个区间（第一个区间必选
    while(s < n){
      int i;
      for(i = 0;i < n+1;i++){
        if(ras[i][0] <= ras[currange][1] && ras[i][1] > ras[currange][1]){
         s = ras[i][1];
         currange = i;
         ans++;
         break;
        }
      }
        if(i >= n) return -1;
    }
    if(s >= n) return ans;
    return -1;
  }
};
