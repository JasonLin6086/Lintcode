/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/add-and-search-word
@Language: C++
@Datetime: 15-11-16 01:15
*/

class TrieTree {
public:
    TrieTree * children[26];
    bool isWord;
};

class WordDictionary {
private:
    TrieTree * root;
public:
    WordDictionary () {
        root = new TrieTree();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        int size = word.size();
        unsigned int i;
        TrieTree * curr = root;
        for (i=0; i<size; i++) {
            if (!curr->children[word[i]-'a']) {
                curr->children[word[i]-'a'] = new TrieTree();
            }
            curr = curr->children[word[i]-'a'];
        }
        curr->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        return searchWord(word, root, 0);
    }
    
    bool searchWord(string word, TrieTree *p, int i) {
        if (i == word.size()) {
            return p->isWord;
        }
        if (word[i] == '.') {
            for (auto &a : p->children) {
                if (a && searchWord(word, a, i + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            return p->children[word[i] - 'a'] && 
                   searchWord(word, p->children[word[i] - 'a'], i + 1);
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
