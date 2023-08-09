/*
 * main.cpp
 *
 * Includes the main() function for the graph BFS project.
 *
 * This code creates the executable run-main.
*/

#include <iostream>

#include "graph.h"

using namespace std;

int main() {
    // You can use this main() to run your own analysis or testing code.
    cout << "If you are seeing this, you have successfully run main!" << endl;

    graph test(5);
    graph *t1 = new graph(5);
    test.add_edge(0,3);
    test.add_edge(0,1);
    test.add_edge(1,2);
    test.add_edge(3,1);
    test.add_edge(4,1);
    vector<int> v = test.find_shortest_path(0,2);

    for(auto &num: v){
        cout << num << endl;
    }

    delete t1;

    return 0;
}
