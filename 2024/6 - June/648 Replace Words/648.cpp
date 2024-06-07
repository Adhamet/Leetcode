class TrieNode {
    public:
        bool isEnd;
        vector<TrieNode*> children;

        TrieNode(): children(26,nullptr) { isEnd = false; }
};

class Trie {
    private:
        TrieNode* root;
    
    public:
        Trie() { root = new TrieNode(); }

        void insert(string word) {
            TrieNode* current = root;
            for(char c: word) {
                if(current->children[c - 'a'] == nullptr) {
                    current->children[c - 'a'] = new TrieNode();
                }

                current = current->children[c - 'a'];
            }
            current->isEnd = true;
        }

        string shortestRoot(string word) {
            TrieNode* current = root;
            for(int i = 0; i < word.length(); i++) {
                char c = word[i];
                if(current->children[c - 'a'] == nullptr) {
                    return word;
                }

                current = current->children[c - 'a'];
                if(current->isEnd) {
                    return word.substr(0, i + 1);
                }
            }

            return word;
        }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream s(sentence);
        string word, ansS;
        
        Trie dictTrie;
        for(string word: dictionary) dictTrie.insert(word);

        while(s >> word) {
            ansS += dictTrie.shortestRoot(word) + " ";
        }
        
        ansS.pop_back();
        return ansS;
    }
};
