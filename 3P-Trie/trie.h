/*
 * trie.h
 *
 * Declaration of the trie class.
 * 
 * Author: <your name here>
 */

#ifndef _TRIE_H
#define _TRIE_H

#include <string>
#include <vector>
#include "node.h"

using namespace std;

class trie {
public:
    trie();
    ~trie();
    void insert(const string &s);
    bool contains(const string &s);
    bool is_prefix(const string &s);
    void extend(const string &prefix, vector<string> &result);
    int charToInt(char &c);
    char intToChar(int index);
    void preOrder(trieNode* &pCurrent, vector<string> &result, string &prefix);

private:
    trieNode* root;
    //bool prefixHelper(int index, trieNode* pCurrent);
};

#endif
