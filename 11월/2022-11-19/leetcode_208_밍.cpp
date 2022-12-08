class Trie {
public:
    set<string> s, pf;
    
    Trie() {
        s.clear();
        pf.clear();
    }
    
    void insert(string word) {
        s.insert(word);
        string str = "";
        for (auto c: word) {
            str += c;
            pf.insert(str);
        }
    }
    
    bool search(string word) {
        if (s.find(word) != s.end()) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        if (pf.find(prefix) != pf.end()) return true;
        else return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */