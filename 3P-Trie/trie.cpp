/*
 * trie.cpp
 *
 * Method definitions for the trie class.
 *
 * Author: Gary Rabinovich
 */

#include "trie.h"
#include <iostream>
using namespace std;



    // trie::trie(){

    // }
    // trie::~trie(){

    // }
    // // void trie::insert(const string &s){

    // // }
    // // bool trie::contains(const string &s){

    // // }
    // // bool trie::is_prefix(const string &s){

    // // }
    // void trie::extend(const string &prefix, vector<string> &result){

    // }
    // // int trie::charToInt(char &c){

    // // }
    // char trie::intToChar(int index){

    // }
    // void trie::preOrder(trieNode* &root, vector<string> &result){

    // }

    trie::trie(){
        root = new trieNode;
    }

    trie::~trie(){
        delete root;
    }

    void trie::insert(const string &s){
        char c;
        trieNode* pCurrent = root;
        for(size_t i = 0; i < s.size(); i++){
            c = s[i];
            int index = charToInt(c);
            if(pCurrent->children[index] == nullptr){
                pCurrent->children[index] = new trieNode;
                pCurrent->size++;
            }
            pCurrent = pCurrent->children[index];
        }

        pCurrent->is_terminal = true;
    }

    bool trie::contains(const string &s){
        char c;
        trieNode* pCurrent = root;
        for(size_t i = 0; i < s.size(); i++){
            c = s[i];
            int index = charToInt(c);
            if(pCurrent->children[index] != nullptr){
               pCurrent = pCurrent->children[index];
            }else{
                return false;
            }
        }
        return pCurrent->is_terminal;
    }

    bool trie::is_prefix(const string &s){
        char c;
        trieNode* pCurrent = root;

        for(size_t i = 0; i < s.size(); i++){
            c = s[i];
            int index = charToInt(c);
            if(pCurrent->size > 1){
                if(i+1 == s.size()){
                    pCurrent = pCurrent->children[index];
                    if(pCurrent->is_terminal){
                        return true;
                    }
                }
                return false;
            }else{
                pCurrent = pCurrent->children[index];
            }
        }
        return true;
    }

    void trie::extend(const string &prefix, vector<string> &result){
        char c;
        trieNode* pCurrent = root;
        string prefix_copy = prefix;
        for(size_t i = 0; i < prefix.size(); i++){
            c = prefix[i];
            int index = charToInt(c);
            if(pCurrent->children[index]){
                pCurrent = pCurrent->children[index];
            }else{
                return;
            }
        }

        preOrder(pCurrent,result,prefix_copy);

    }

    int trie::charToInt(char &c){
        int a = int(c);
        return (a-97);
    }

    char trie::intToChar(int index){
        char c = char(index+97);
        return c;
    }


    void trie::preOrder(trieNode* &pCurrent, vector<string> &result, string &prefix){
        if(pCurrent->is_terminal){
            result.push_back(prefix);
        }
        for(int i = 0; i < 26; i++){
            if(pCurrent->children[i]){
                prefix.push_back(i+'a');
                preOrder(pCurrent->children[i],result,prefix);
                prefix.pop_back();
            }
        }
    }

    // bool trie::prefixHelper(int index, trieNode* pCurrent){
    //     if(pCurrent->size > 1 && pCurrent->is_terminal != true){
    //         return false;
    //     }
    //     return true;
    // }