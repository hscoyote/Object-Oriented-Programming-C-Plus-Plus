#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief prints the elements in the array and their memory locations
 * 
 * @param v - vector of integers
*/
// void printMemVec(...){


void printMemVec(vector<int> vec) { //void printMemArr(intarr[], int size)}
    printf("Vector - each int is worth %lu bytes \n", sizeof(vec[0]));
    for(int i = 0; i < vec.size(); i++) {
        printf("Value :%i at Memory Location: %p\n", vec[i], &vec + i);
    }
}


// }


/**
 * @brief increments all of the elements in v by 10
 * 
 * @param v - address to a vector of integers 
*/
void incVecBy10(vector<int> & vec) { //void incArrnBy10(int arr[], int size)
    for( int i = 0; i < vec.size(); i++) {
        vec[i] += 10;
    }
}



int main() {
    //create a constant integer called SIZE that is of value 5
    const int SIZE = 5; 
    //create a vector integers caled vec that can hold up to 5 elements 
    vector<int> vec(SIZE);
    //use a for loop to populate vec with the values 100 to 104
    for(int i = 0; i < SIZE; i++) {
        vec[i] = 100 + i;
    }
    printf("Before Increment---------------\n");
    //call printMemVec(...) on vec 
    printMemVec(vec);
    //call incBy10(...) on vec 
    incVecBy10(vec);

    printf("After Increment------------------\n");
    //call printMemVec(...) on vec again to view the changes
    printMemVec(vec);

    //remove last element of the vec
    //(refer to docs https://cplusplus.com/reference/vector/vector/#google_vignette)
    vec.pop_back();


    printf("After Pop-------------------\n");
    //call printMemVec(...) on vec again to view the changes
    printMemVec(vec);
    //append 101 and 102 at the end of vec
    // (refer to docs https://cplusplus.com/reference/vector/vector/#google_vignette)
    vec.push_back(101);
    vec.push_back(102);

    printf("After Push---------------\n");
    //call printMemVec(...) on vec again to view the changes 
    printMemVec(vec);
    return 0;
}