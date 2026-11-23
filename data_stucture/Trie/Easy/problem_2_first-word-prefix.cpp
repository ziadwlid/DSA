#include <cassert>
#include <iostream>
using namespace std;

namespace Trie{
    class TrieNode {
    private:
        static const int MAX_CHAR = 26;
        TrieNode* children[MAX_CHAR];
        bool isLeaf{};

    public:
        TrieNode() : children{}, isLeaf(false) {}

        TrieNode(const TrieNode& other) : children{}, isLeaf(other.isLeaf) {
            for (int i = 0; i < MAX_CHAR; i++) {
                if (other.children[i] != nullptr)
                    children[i] = new TrieNode(*other.children[i]);
            }
        }

        TrieNode& operator=(const TrieNode& other) {
            if (this == &other)
                return *this;

            for (int i = 0; i < MAX_CHAR; i++) {
                delete children[i];
                children[i] = nullptr;

                if (other.children[i] != nullptr)
                    children[i] = new TrieNode(*other.children[i]);
            }

            isLeaf = other.isLeaf;
            return *this;
        }

        TrieNode*& operator[](const int index) {
            assert(index >= 0 && index < MAX_CHAR);
            return children[index];
        }

        ~TrieNode() {
            for (int i = 0; i < MAX_CHAR; i++)
                delete children[i];
        }
        void insert(string &str, int index) {
            if (index == static_cast<int>(str.length()))
                isLeaf = true;
            else {
                int cur = str[index] - 'a';
                if (children[index] == nullptr)
                    children[cur] = new TrieNode();
                children[index]->insert(str, index + 1);
            }
        }
        bool search(string &str, int index = 0) {
            if (index == static_cast<int>(str.length()))
                return isLeaf;
            int cur = str[index] - 'a';
            if (!children[index])
                return false;
            return children[index]->search(str, index + 1);
            }
        bool prefixSearch(string &str, int index = 0) {
            if (index == static_cast<int>(str.length()))
                return true;
            int cur = str[index] - 'a';
            if (!children[index])
                return false;
            return children[index]->prefixSearch(str, index + 1);
        }
        void insert_v2(string & str) {
            auto cur = this;
            for (int i = 0; i < static_cast<int>(str.length()); ++i) {
                const int idx = str[i] - 'a';
                if (!cur->children[idx])
                    cur->children[idx] = new TrieNode();
                cur = cur->children[idx];
            }
            cur->isLeaf = true;
        }
        bool word_exist(string str) {
            auto cur = this;
            for (int i = 0; i < static_cast<int>(str.length()); ++i) {
                const int idx = str[i] - 'a';
                if (!cur->children[idx])
                    return false;
                cur = cur->children[idx];
            }
            return cur->isLeaf;
        }

        string first_word_prefix(const string &str) {
            string out = "";
            TrieNode* cur = this;

            for (int i = 0; i < (int)str.length(); ++i) {
                const int idx = str[i] - 'a';
                if (!cur->children[idx])
                    return out;
                out += str[i];
                cur = cur->children[idx];
                if (cur->isLeaf)
                    return out;
            }
            return out;
        }
    };
}
