/*
 * hashtable.h
 *
 * A basic hashtable implementation.
 * 
 * Author: <your name here>
 */

#ifndef _HASHTABLE_PROJECT_H
#define _HASHTABLE_PROJECT_H

#include <functional>   // for std::hash
#include <vector>
#include <list>
#include <utility>

using namespace std;

template <class T, class H = std::hash<T>>
class hashtable {
public:
    // constructor
    hashtable(){
        size1 = 0;
        tableSize = 4;
        hashTable = new vector<list<T>*>;
        for(size_t i = 0; i < tableSize; i++){
            hashTable->push_back(new list<T>);
        }
    }
    
    void insert(const T& key){
        size_t code = hash(key)%tableSize;

        if(contains(key)){
             return;
        }
        double lf = double((size1 + 1));
        lf /= double(tableSize);

        if(lf > 0.75){
            this->resize();
            code = hash(key)%tableSize;
            hashTable->at(code)->push_back(key);
            size1++;
            return;
        }

        hashTable->at(code)->push_back(key);
        size1++;
    }

    // void insert(const T& key){
    // }
    // void remove(const T& key){

    // }
    // bool contains(const T& key){

    // }
    // size_t size(){

    // }
    // double load_factor(){

    // }
    

    void remove(const T& key){
        size_t code = hash(key)%tableSize;
        for(auto it = hashTable->at(code)->begin(); it != hashTable->at(code)->end(); it++){
            if(*it == key){
                hashTable->at(code)->erase(it);
                break;
            }
        }
        if(size1 > 0){
            size1--;
        }

    }

    bool contains(const T& key){
        size_t code = hash(key)%tableSize;
        for(auto it = hashTable->at(code)->begin(); it != hashTable->at(code)->end(); it++){
            if(*it == key){
                return true;
            }
        }
        return false;
    }

    size_t size(){
        return size1;
    }

    double load_factor(){
        double siz = size1;
        siz /= tableSize;
        return siz;
    }

    static size_t hash(const T &key) {
        H h;
        return h(key);
    }
 private:
    size_t size1;
    size_t tableSize;
    vector<list<T>*> *hashTable;
    void resize(){
        size_t temp(tableSize),level(0),bucket(0),Hash;
        tableSize *= 2;
        vector<list<T>*> *tempList = new vector<list<T>*>(tableSize);
        for(size_t i = 0; i < tableSize; i++){
           tempList->at(i) = new list<T>;
        }
        while(bucket < temp) {
            for(auto it = hashTable->at(level)->begin(); it != hashTable->at(level)->end(); it++){
                Hash = hash(*it)%tableSize;
                tempList->at(Hash)->push_back(*it);
            }
            level++;
            bucket++;
        }
            cleanup(temp,hashTable);
            hashTable = tempList;
    }

    void cleanup(size_t tableSize, vector<list<T>*> *tempList){
        for(size_t i = 0; i < tableSize; i++){
            tempList->at(i)->clear();
        }
        delete tempList;
    }
};

#endif
