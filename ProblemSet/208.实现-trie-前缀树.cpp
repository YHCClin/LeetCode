/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include "Include_all.h"
using namespace std;
// @lc code=start
struct TrieNode {
    bool isWord;
    TrieNode* childNode[26];
    TrieNode(bool f=false) : isWord(f) {memset(childNode,NULL,sizeof(childNode));}
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for(int i = 0;i < word.size();++i) {
            int ch = word[i] - 'a';
            if(cur->childNode[ch] == NULL) {
                cur->childNode[ch] = new TrieNode(i==(word.size()-1));
            }
            else if(cur->childNode[ch] != NULL && i==word.size()-1) {
                cur->childNode[ch]->isWord = true;
            }
            cur = cur -> childNode[ch];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for(int i = 0;i < word.size();++i) {
            int ch = word[i] - 'a';
            if(cur->childNode[ch]==NULL) return false;
            else {
                if(i == word.size()-1 && cur->childNode[ch]->isWord) return true;
                cur = cur -> childNode[ch];
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        TrieNode* cur = root;
        for(int i = 0;i < word.size();++i) {
            int ch = word[i] - 'a';
            if(cur->childNode[ch]==NULL) return false;
            cur = cur -> childNode[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

