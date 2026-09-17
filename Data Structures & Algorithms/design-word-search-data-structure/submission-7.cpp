class TrieNode {
public:
    unordered_map<char,TrieNode*> children;
    bool eow = false;
};

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word)
        {
            if (curr->children.find(c) != curr->children.end())
            {
                curr = curr->children[c];
            }
            else
            {
                curr->children[c] = new TrieNode();
                curr = curr->children[c];
            }
        }
        curr->eow = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(TrieNode* root, string & word, int i)
    {
        if (!root) return false;
        if (i == word.size()) return root->eow;

        char c = word[i];
        if (c == '.')
        {
            //recursively search all possible subtrees
            for (auto [letter, node] : root->children)
            {
                // if the branch suceeds
                if (dfs(node, word, i + 1))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            if (root->children.find(c) == root->children.end())
            {
                //letter not found
                return false;
            }
            return dfs(root->children[c], word, i + 1);
        }

        return false;
    }
};
