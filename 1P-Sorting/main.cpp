/*
 * main.cpp
 *
 * Includes the main() function for the sorting project. 
 *
 * This code is included in the build target "run-main"
*/

#include <iostream>
#include <cstddef>
#include <vector>

#include "sorter.h"

using namespace std;

int main() {
    // You can use this main() to run your own analysis or testing code.
    vector<int> v = {1,2,5,4,7,9,5,0};
    sorter(v,3);
    cout << "If you are seeing this, you have successfully run main!" << endl;
    return 0;
}


