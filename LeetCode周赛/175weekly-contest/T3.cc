#include <bits/stdc++.h>
using namespace std;

struct tweet{
    string tweetName;
    int tweetTime;
    tweet* next;
    tweet(string n, int t) : tweetName(n), tweetTime(t), next(NULL) {}
};
class TweetCounts {
public:
    tweet *database = new tweet("None",-1);
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweet *nt = new tweet(tweetName,time);
        tweet *p = database;
        while(p->next != NULL)
        {
            if(p -> next -> tweetTime < time)
                p = p -> next;
            else break;
        }
        tweet *r = p -> next;
        p -> next = nt;
        nt -> next = r;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int delta;    
        if(freq == "minute") delta = 60;
        else if(freq == "hour") delta = 3600;
        else delta = 86400;
        vector<int> ans;
        tweet *p = database -> next;
        if(p == NULL) return ans;
        int cnt = 0, k = 2;
        int left=startTime,right=min(startTime+delta,endTime+1);
        while(left <= endTime)
        {
            cnt = 0;
            while(p != NULL && p -> tweetTime < right)
            {
                if( p -> tweetName == tweetName && p -> tweetTime >= left)
                    cnt ++;
                p = p -> next;
            }
            ans.push_back(cnt);
            left = startTime + delta*(k-1); right = min(startTime + delta*k, endTime+1);
            k++;
        }
        if(p == NULL && left <= endTime) ans.push_back(0);
        /*
        if(ans.size() > 1)
        {
            auto it = ans.end()-1;
            while((*it) == 0) {ans.erase(it); it--;}
        }
        */
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */

int main()
{
	TweetCounts* tweetCounts = new TweetCounts();
	tweetCounts->recordTweet("tweet3", 0);
	tweetCounts->recordTweet("tweet3", 60);
	tweetCounts->recordTweet("tweet3", 10);                             // "tweet3" 发布推文的时间分别是 0, 10 和 60 。
	vector<vector<int>> ans;
	ans.push_back(tweetCounts->getTweetCountsPerFrequency("minute", "tweet3", 0, 59)); // 返回 [2]。统计频率是每分钟（60 秒），因此只有一个有效时间间隔 [0,60> - > 2 条推文。
	ans.push_back(tweetCounts->getTweetCountsPerFrequency("minute", "tweet3", 0, 60)); // 返回 [2,1]。统计频率是每分钟（60 秒），因此有两个有效时间间隔 1) [0,60> - > 2 条推文，和 2) [60,61> - > 1 条推文。 
	tweetCounts->recordTweet("tweet3", 120);                            // "tweet3" 发布推文的时间分别是 0, 10, 60 和 120 。
	ans.push_back(tweetCounts->getTweetCountsPerFrequency("hour", "tweet3", 0, 210));  // 返回 [4]。统计频率是每小时（3600 秒），因此只有一个有效时间间隔 [0,211> - > 4 条推文。
	for(auto v : ans)
	{
		for(auto j : v)
			cout << j << " ";
		cout << endl;
	}
}