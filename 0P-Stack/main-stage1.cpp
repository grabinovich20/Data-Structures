/*
 * main-stage1.cpp
 *
 * Includes the main() function for the stack project (stage 1).
 *
 * This code is included in the build target "run-stage1-main", and
 * in the convenience target "stage1".
 */

#include <iostream>

#include "stack-stage1.h"

using namespace std;

int main() {
    stack stk;
    stk.push("a");
    stk.push("b");
    stk.push("c");
    stk.top();
    cout << "If you are seeing this, you have successfully run main!" << endl;
    return 0;
}
