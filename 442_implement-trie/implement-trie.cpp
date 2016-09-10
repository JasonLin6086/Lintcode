/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/implement-trie
@Language: C++
@Datetime: 16-06-30 01:30
*/

/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *child[26];
    bool isWord=false;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (int i=0; i<word.size(); i++) {
            if (!p->child[word[i]-'a']) p->child[word[i]-'a'] = new TrieNode();
            p = p->child[word[i]-'a'];
        }
        p->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * p = root;
        for (int i=0; i<word.size(); i++) {
            if (!p->child[word[i]-'a']) return false;
            p = p->child[word[i]-'a'];
        }
        return p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * p = root;
        for (int i=0; i<prefix.size(); i++) {
            if (!p->child[prefix[i]-'a']) return false;
            p = p->child[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};