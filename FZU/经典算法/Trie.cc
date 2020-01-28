#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
using namespace std;
// 结点定义
struct TrieNode {
    char nodeChar;
    int freq;
    bool isWord;
    vector<TrieNode*> childNode;
    TrieNode()
    {
        freq = 0;
        isWord = false;
        childNode = vector<TrieNode*>(26,NULL);
    }
};

// 添加操作
void addWord(TrieNode* root, string word, int k)
{
    if(k >= word.size()) return;

    // 将word的首字母插入到root的哪一个分叉中
    int index = word[k] - 'a';
    // 若该树为空，插入新结点
    if(root->childNode[index] == NULL)
    {
        root->childNode[index] = new TrieNode();
        root->childNode[index]->nodeChar = word[0];
        if(k == word.size()-1)
        {
            // 终端结点标记
            root->childNode[index]->isWord = true;
        }
        addWord(root->childNode[index], word, k+1);
    }
    else
    {
        if(k == word.size()-1)
        {
            root->childNode[index]->isWord = true;
        }
        // 递归添加结点
        addWord(root->childNode[index], word, k+1);
    }
}

// 查询操作
bool searchWord(TrieNode* root, string word)
{
    TrieNode* p = root;
    int i;
    for(i = 0;i < word.size() && p != NULL;i++)
    {
        int index = word[i] - 'a';
        if(p->childNode[index] == NULL)
        {
            return false;
        }
        else
        {
            if(i == word.size()-1)
                p->childNode[index]->freq++;
            p = p->childNode[index];
        }
    }
    if(i == word.size() && p->isWord)
        return true;
    else return false;
}

/*
    删除操作：
        删除操作比较复杂，分三种情况：
            1. 删除整个单词 （该单词的尾结点为叶子节点，且该单词独占一条路径）
            2. 删除前缀词 （该单词的尾结点非叶子节点）
            3. 删除分支单词 （该单词的尾结点为叶子节点但存在于其他单词共用的路径）
 */
bool isLeave(TrieNode* node)
{
    for(int i = 0;i < 26;i++)
    {
        if(node->childNode[i] != NULL)
        {
            return false;
        }
    }
    return true;
}
void deleteWord(TrieNode* root, string word, int k)
{
    if(k >= word.size()) return;
    cout << "delete into " << word[k] << endl;
    int index = word[k] - 'a';
    if(root->childNode[index] == NULL) return;
    else
    {
        cout << 'd' << endl;
        deleteWord(root->childNode[index], word, k+1);
        if(isLeave(root) && !root->isWord)
        {
            cout << "dc" << endl;
            delete root;
            root = NULL;
        }
        else if(k == word.size()-1 && !isLeave(root))
        {
            root->isWord = false;
            cout << "dd" << endl;
        }
    }
}
bool DeleteKey(TrieNode *root, string word)
{
    if(searchWord(root, word))
    {
        deleteWord(root, word, 0);
        return true;
    }
    return false;
}

// dfs 输出字典树中的所有关键词
void printTrie(TrieNode *root,string& cur)
{
    if(root)
    {
        for(int i = 0;i < 26;i++)
        {
            if(root->childNode[i] != NULL)
            {
                cur += char('a' + i);
                if(root->childNode[i]->isWord)
                    cout << cur << endl;
                printTrie(root->childNode[i],cur);
                cur = cur.substr(0,cur.size()-1);
            }
        }
    }
}
int main()
{
    TrieNode* root = new TrieNode();
    vector<string> words = {"code","cook","five","file","fat","fire","hello"};
    for(auto s : words)
    {
        addWord(root, s, 0);
    }
    string cur = "";
    printTrie(root, cur);
    cout << searchWord(root, "file") << endl;
    cout << searchWord(root, "fat") << endl;
    cout << searchWord(root, "fi") << endl;
    cout << searchWord(root, "fa") << endl;

    cout << DeleteKey(root, "fat") << endl;
    cout << searchWord(root, "fat") << endl;
    string cur_ = "";
    printTrie(root, cur_);
}