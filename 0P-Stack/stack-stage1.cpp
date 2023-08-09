/*
 * stack.cpp
 *
 * Method definitions for the stack implementation.
 *
 * Author: Gary Rabinovich
 */

#include "stack-stage1.h"

string stack::top() {
    if(number == 0){
        return "";
    }
    return data[number - 1];
}

void stack::push(const string &name){
    if(number == capacity){
        capacity *= 2;
        string *replace = new string[capacity];
        for(int i = 0; i < number; i++){
            replace[i] = data[i];
        }
        delete[] data;
        data = replace;
        replace = nullptr;
    }
    data[number] = name;
    number++;
}

void stack::pop(){
    if(number == 0){
        return;
    }else{
        number--;
    }
}

bool stack::is_empty(){
    if(number == 0)
        return true;
    else
        return false;
}

stack::stack(){
    number = 0;
    capacity = 1;
    data = new string[capacity];
}