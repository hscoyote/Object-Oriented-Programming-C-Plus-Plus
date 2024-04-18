#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>
using namespace std; 

/**
 * @brief returns the first index of elem if it exists, otherwise returns -1
 * iterativeSearch starts at the first index and iterates sequentially to the next until it either
 * finds the element or until it reaches the end (i.e. element DNE)
 * @param v : vector of elements
 * @param elem : integer to look for 
 * @return int 
 * 
*/
int iterativeSearch(vector<int>v, int elem){
    //use a for loop where the index i goes from 0 to the size of v 
    for( int i = 0; i == v.size(); i++){
        if(v[i] == elem) {
            return i;
        }      
    }
    return -1;
    //inside the for loop use an if statement to check whether the element at i (e.g. v[i]) equals elem
    //inside the if statement return i 


    //outside the for loop return -1
}

/**
 * @brief returns the index of elem, if it exists in v. Otherwise it returns -1.
 * binarySearch is recursive (i.e. function calls itself).
 * It utilizes the fact that v is increasing order (e.g. values go up
 * and duplicates are not allowed)
 * 
 * It calculates the mid from the start and end index. It compares v[mid] (i.e.
 * value at mid) with elem and decides whether to search the left half (lower values) 
 * or right half (upper values).
 * 
 * 
 * @param v : vector of elements
 * @param start : leftmost index (starting value is 0)
 * @param end : rightmost index (starting value is v.size())
 * @param elem : integer to look for
 * @return int 
*/
int binarySearch(vector<int> & v, int start, int end, int elem){
    if(start > end){ 
        return -1; 
    }

    int mid = (start + end) / 2; //instantiates the midpoint

    if(v[mid] > elem ) { //search left half
        end = mid - 1;
    } else if (v[mid] < elem ) { //search right half
        start = mid + 1;
    } else {
        return mid; 
    }
    return binarySearch(v, start, end, elem);
}

/**
 * @brief updates v to containt he calues from filename (leave as is)
 * 
 * It is expected that the files containing values ranging from one to 
 * one hundred million in ascending order (no duplicates)
 * 
 * @param filename : string 
 * @param v : vector 
*/

void vecGen (string filename, vector<int> & v){
    ifstream file(filename);
    int num;
    v.clear();
    while (file.is_open() && file >> num){
        v.push_back(num);
    }
    file.close();
}


int main(){
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    for(int i = 0; i < elem_to_find.size(); i++) {
        int elem = elem_to_find[i];

     auto start = chrono::high_resolution_clock::now();
    int index_if_found = iterativeSearch(v, elem);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Time taken by iterative search: " << duration.count() << " microseconds" << endl;



    }

    for(int i = 0; i < elem_to_find.size(); i++) {
        int elem = elem_to_find[i];

     auto start = chrono::high_resolution_clock::now();
    int index_if_found = binarySearch(v, 0, v.size(), elem);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Time taken by binarySearch: " << duration.count() << " microseconds" << endl;
    }

}