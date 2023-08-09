/*
 * sorter.h
 *
 * Declares a template function:
 *    
 *   sorter() : k-way merge sort.
 * 
 * 
 * You may add other functions if you wish, but this template function
 * is the only one that need to be exposed for the testing code.
 * 
 * Authors: C. Painter-Wakefield & Tolga Can
 */

#ifndef _SORTER_H
#define _SORTER_H

#include <string>
#include <cstddef>
#include <vector>
#include <algorithm>

using namespace std;


template <class T>
void sorter(vector<T> &vec, int k) {  

	if(vec.size() == 0 || vec.size() == 1){   //if the initial vector has a size of 0 or 1 then it is already sorted
		return;
	}

	//math to divide vector k times
	vector<vector<T>> list;
	int k1 = vec.size()%k;
	int size = vec.size()/k;
	int size2 = k-k1;
	int index = 0;

	for(int i = 0; i < k1; i++){
		vector<T> v(size+1);
		v.assign(vec.begin()+index,vec.begin()+index+(size+1));
		list.push_back(v);
		index += size+1;
	}	

	for(int i = 0; i < size2; i++){
		vector<T> v(size);
		v.assign(vec.begin()+index,vec.begin()+index+size);
		list.push_back(v);
		index += size;
	}
	
	//recursively calling sorter to keep dividing the vector
	for(int i = 0; i < k; i++){
		if(list[i].size() > 1){
			sorter(list.at(i),k);
		}
	}

	//start of merge
	T min;
	int j;
	index = 0;
	vector<size_t> indexList(k,0);

	for(size_t i = 0; i < vec.size(); i++){
		j=0;
		while(indexList[j] >= list[j].size()){
			j++;
		}
		//set min to the first value found of that index
		index = j;
		min = list[j][indexList[j]];
		//traversing the vector to see if there is a different min
		while(j+1 < k){
			j++;
			if(indexList[j] < list[j].size()){
				if(list[j][indexList[j]] < min){
					index = j;
					min = list[j][indexList[j]];
				}
			}
		}
		indexList.at(index)++;
		vec.at(i) = min; //setting the min in the vector
	}
}
#endif
