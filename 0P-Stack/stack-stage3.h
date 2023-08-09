/*
 * stack.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Gary Rabinovich
 */


// To start stage 2, you probably want to copy all of your code from
// stack-stage1.h and stack-stage1.cpp in place of this comment.

#ifndef _STACK_H
#define _STACK_H

#include <cstddef> // for size_t
#include <string>  // for stage 1

using namespace std;

template <typename T>
class stack {
  public:
        T top(){  
            if(number != 0){
                return data[number - 1];
            }  
            return data[0];
        }

    void push(const T &name){
        if(number == capacity){
            capacity *= 2;
            T *replace = new T[capacity];
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

    void pop(){
        if(number == 0){
            return;
        }else{
            number--;
        }
    }

    size_t size() { 
        return number; 
    }

    bool is_empty(){
        if(number == 0)
            return true;
        else
            return false;
    }

    stack(){
        number = 0;
        capacity = 1;
        data = new T[capacity];
    }

    ~stack(){
        deleting();
    }

    stack(const stack<T> &newStack){
        copying(newStack,false);
    }

    stack& operator=(const stack<T> &newStack){
        if(this != &newStack){
            copying(newStack, true);
        }
        return *this;
    }

  private:
    T *data;
    int number;
    int capacity;
    void deleting(){
        delete[] data;
    }
    void copying(const stack<T> &newStack, bool assignment){
        number = newStack.number;
        capacity = newStack.capacity;
        if(assignment == true){
            deleting();
        }
        data = new T[number];
        for(int i = 0; i < number; i++){
            data[i] = newStack.data[i];
        }
    }
};

#endif