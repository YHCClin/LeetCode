#include "Include_all.h"
using namespace std;
// 设计一个简易的推特
struct twitter {
    int userId;
    int tweetId;
    twitter *next;
    twitter(int uid,int tid) : userId(uid), tweetId(tid), next(NULL) {}
};

class Twitter {
public:
    /** Initialize your data structure here. */
    twitter *twitters;                  // 存储所有推文的链表
    map<int, set<int>> follows;         // 记录每个user的关注列表
    Twitter() {
        twitters = new twitter(-1,-1); // 初始化头结点
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        // 头插法
        twitter *nt = new twitter(userId, tweetId);
        nt -> next = twitters->next;
        twitters->next = nt;            // 添加推文
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        // 遍历推文链表
        twitter *p = twitters -> next;
        vector<int> tlist;
        int cnt = 0; // 控制推文输出数量(小于等于10)
        while(p && cnt < 10)
        {
            if(p->userId == userId || follows[userId].find(p->userId) != follows[userId].end())
            {
                tlist.push_back(p->tweetId);
                cnt++;
            }
            p = p -> next;
        }
        return tlist;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main()
{
    Twitter* obj = new Twitter();
    obj->postTweet(1,5);
    obj->postTweet(2,6);
    vector<int> param_2 = obj->getNewsFeed(1);
    obj->follow(1,2);
    vector<int> param_2 = obj->getNewsFeed(1);
    obj->unfollow(1,2);
    vector<int> param_2 = obj->getNewsFeed(1);
    return 0;
}