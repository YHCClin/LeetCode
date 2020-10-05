/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU缓存 = 哈希表 + 平衡二叉树
 */
// @lc code=start
struct Node {
    // 缓存使用频率，缓存最近使用时间戳，键，值
    int cnt, time, key, value;
    // 构造函数
    Node(int c, int t, int k, int v) : cnt(c), time(t), key(k), value(v) {}
    // Node 比较函数, 用于set的自动排序
    bool operator< (const Node& rhs) const {
        // 按增序，优先级：cnt -> time
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};
class LFUCache {
    // 缓存容量，访问时间戳
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> S; // 其底层实现为红黑树
    
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }
    
    int get(int key) {
        if(capacity == 0) return -1;
        auto iter = key_table.find(key); 
        if(iter == key_table.end()) return -1; // 判断是否存在key
        Node cache = iter -> second; // 取下拷贝
        S.erase(cache); // 删除旧缓存, 因为红黑树不会动态调整，只能摘下来重新插入进去
        // 更新旧缓存
        cache.time = ++time; // 记录最近访问时间
        cache.cnt++;        // 访问频次增加 1
        // 将新缓存重写放入哈希表和平衡二叉树中
        S.insert(cache);
        iter -> second = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        auto iter = key_table.find(key);
        if(iter == key_table.end()) {
            // 新缓存,插入
            if(key_table.size() == capacity) {
                // 容量已满，删除最近最少使用的缓存
                key_table.erase(S.begin() -> key);
                S.erase(S.begin());
            }
            // 容量有余，创建新缓存
            Node cache = Node(1, ++time, key, value);
            // 放入哈希表和二叉树中
            key_table.insert(make_pair(key,cache));
            S.insert(cache);
        } else {
            // 已存在的缓存, 处理与get类似, 不过多了一个将value该表的操作
            Node cache = iter -> second;
            S.erase(cache);
            cache.cnt++;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            iter -> second = cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

