
class Trie
{
private:
    map<char, Trie *> child;
    bool leaf;

    Trie *searchPrefix(string prefix)
    {
        Trie *node = this;
        for (char c : prefix)
        {
            if (node->child.find(c) == node->child.end())
                return nullptr;
            node = node->child[c];
        }
        return node;
    }

public:
    Trie()
    {
        leaf = false;
    }

    void insert(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            if (node->child.find(c) == node->child.end())
            {
                Trie *tr = new Trie();
                node->child[c] = tr;
            }
            node = node->child[c];
        }
        node->leaf = true;
    }

    bool search(string word)
    {
        Trie *node = this->searchPrefix(word);
        if (node == nullptr) return false;
        return node->leaf;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this->searchPrefix(prefix);
        if (node == nullptr) return false;
        return true;
    }
};