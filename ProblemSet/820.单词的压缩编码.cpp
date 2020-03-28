/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

// @lc code=start
#include "Include_all.h"
using namespace std;

// 比较函数, 按字符串长度排序
bool cmp(const string &a, const string &b){
    return a.size() > b.size();
}

// Trie树节点
struct TrieNode {
    TrieNode* childNode[26];
    TrieNode() {memset(childNode, NULL, sizeof(childNode));}
};

// Trie 树类
class TrieTree {
public:
    TrieNode* root; // 根节点指针
    TrieTree() {root = new TrieNode();}
    int insertWord(string &word) { // 插入单词的函数
        TrieNode* cur = root;
        bool isNew = false;// 新单词标记
        for(int i = word.size()-1;i >= 0; --i) {
            char ch = word[i];
            if(cur->childNode[ch-'a'] == NULL) { // 非后缀，为新单词
                isNew = true;
                cur->childNode[ch-'a'] = new TrieNode();
            }
            cur = cur->childNode[ch - 'a'];
        }
        return isNew ? word.size() + 1 : 0;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        TrieTree tree; // Trie 树
        sort(words.begin(), words.end(),cmp);
        for(string &w : words) {
            ans += tree.insertWord(w);
        }
        return ans;
    }
};
// @lc code=end

