// 本题会卡常数时间，较旧的高赞数代码也会T

struct Node
{
    Node* children[26];
    bool isEnd; 

    Node()
    {
        memset(children, 0, sizeof(children));
        isEnd = false;
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (char c : word)
        {
            int i = c - 'a';
            if (curr->children[i] == nullptr)
            {
                curr->children[i] = new Node();
            }
            curr = curr->children[i];
        }
        curr->isEnd = true;
    }
    
    bool dfs(string& word, int start, Node* curr)
    {
        if (start == word.size())
        {
            return curr->isEnd;
        }
        
        if (word[start] == '.')
        {
            for (int j = 0; j < 26; ++j)
            {
                if (curr->children[j] != nullptr && dfs(word, start+1, curr->children[j]))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            int i = word[start] - 'a';
            if (curr->children[i] != nullptr)
            {
                return dfs(word, start+1, curr->children[i]);
            }
            else
            {
                return false;
            }
        }
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
