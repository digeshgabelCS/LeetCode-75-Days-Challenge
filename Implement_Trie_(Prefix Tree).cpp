#include <iostream>
#include <string>
using namespace std;

class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };
    
    TrieNode* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) return false;
            node = node->children[idx];
        }
        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << boolalpha;
    cout << "Search apple: " << obj->search("apple") << endl;     // true
    cout << "Search app: " << obj->search("app") << endl;         // false
    cout << "StartsWith app: " << obj->startsWith("app") << endl; // true
    obj->insert("app");
    cout << "Search app: " << obj->search("app") << endl;         // true
    delete obj;
    return 0;
}
