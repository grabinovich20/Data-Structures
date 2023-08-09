/*
 * graph.cpp
 *
 * Method definitions for the graph class.
 *
 * Author: <your name here>
 */

#include "graph.h"
#include <queue>
#include <algorithm>



graph::graph(int vertex_count){
    graphStorage = new vector<vector<int>>(vertex_count);
    visited = new vector<bool>(vertex_count);
}

graph::~graph(){
    delete graphStorage;
    delete visited;
}

void graph::add_edge(int from, int to){
    (*graphStorage)[from].push_back(to);
}

vector<vector<int>>* graph::getStorage() const{
    return graphStorage;
}

vector<int> graph::find_shortest_path(int from, int to){
    for(size_t i = 0; i < visited->size(); i++){
        visited->at(i) = false;
    }

    graph Reverse(visited->size());
    queue<int> q;
    visited->at(from) = true;
    q.push(from);

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(size_t i = 0; i < graphStorage->at(current).size(); i++){
            int temp = graphStorage->at(current)[i];
            if(visited->at(temp) == false){
                visited->at(temp) = true;
                q.push(temp);
                Reverse.add_edge(temp,current);
            }
        }
    }

        vector<int> path;
        vector<vector<int>>* v = Reverse.getStorage();

        if(visited->at(to) == true){
            path.push_back(to);
            while(to != from){
                to = v->at(to).front();
                path.push_back(to);
            }
        }

        reverse(path.begin(),path.end());

        return path;
}