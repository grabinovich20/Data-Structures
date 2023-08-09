struct trieNode{
    trieNode(){
        children = new trieNode*[26];
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        is_terminal = false;
        size = 0;
    }
    ~trieNode(){
        delete children;
    }

        trieNode** children;
        bool is_terminal;
        size_t size;
};