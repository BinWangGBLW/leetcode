#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode *children[26];
    bool isWord;
    TrieNode() : isWord(false) {
        for (auto & a : children) {
            a = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode * root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (char c : word) {
            int index = c - 'a';
            if (!p->children[index]) p->children[index] = new TrieNode();
            p = p->children[index];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (char c : word) {
            int i = c - 'a';
            if (!p->children[i]) return false;
            p = p->children[i];
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (!p->children[i]) return false;
            p = p->children[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
 
 int main() {
 	Trie obj;
 	obj.insert("wangbin");
 	obj.insert("handsome");
 	obj.insert("wangkai");
 	if (obj.search("wangbin")) cout << "can find wangbin in the trie"<< endl;
 	else cout << "cannot find wangbin in the trie" << endl;
 	if (obj.search("xunweijia")) cout << "can find wangbin in the trie"<< endl;
 	else cout << "cannot find xunweijia in the trie" << endl;
 	if (obj.startsWith("wa")) cout << "can find wa prefix in the trie"<< endl;
 	else cout << "cannot find wa prefix in the trie" << endl;
 	return 0; 	
 }
