class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool eow = false;
};

class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {    
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word)
        {
            if (curr->children.find(c) != curr->children.end())
            {
                //that char exists already
                curr = curr->children[c];
            }
            else 
            {
                // if it doesn't exist we should add it
                curr->children[c] = new TrieNode();
                curr = curr->children[c];
            }
        }

        curr->eow = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for (char c : word)
        {
            if (curr->children.find(c) == curr->children.end())
            {
                return false;
            }

            curr = curr->children[c];
        }

        if (curr->eow == false) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char c : prefix)
        {
            if (curr->children.find(c) == curr->children.end())
            {
                return false;
            }

            curr = curr->children[c];
        }

        //It's possible that a word has another word as a prefix, words are prefixes of themself (dog is a prefix of dog...technically)
        // if (!curr->children.empty()) return true;
        // return false;

        return true;
    }
};
