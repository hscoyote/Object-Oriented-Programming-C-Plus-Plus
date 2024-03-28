#include <iostream>
#include <fstream>
using namespace std;

//creates a writetofile for int

void writeToFile(string filename, int * arr, int SAMPLE_SIZE){
    ofstream file(filename);
    int val;

    for(int i = 0; i < SAMPLE_SIZE; i++) {
        file << arr[i];
        file << "\n";
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

//creates a writetofile for string

void writeToFile(string filename, string * arr, int SAMPLE_SIZE){
    ofstream file(filename);
    int val;

    for(int i = 0; i < SAMPLE_SIZE; i++) {
        file << arr[i];
        file << "\n";
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

//creates a writetofile for character

void writeToFile(string filename, char * arr, int SAMPLE_SIZE){
    ofstream file(filename);
    int val;

    for(int i = 0; i < SAMPLE_SIZE; i++) {
        file << arr[i];
        file << "\n";
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

//void readFile

void readFile(string filename){
    string line;

    fstream file (filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
    } else {
        file.close();
    }


}

//int main

int main(){
    const int SAMPLE_SIZE = 10;
    int array_int[SAMPLE_SIZE] = {1,2,3,4,5,6,7,8,9,10};
    string array_str[SAMPLE_SIZE] = {"This", "is", "a", "sentence. ",
                                        "This", "is", "another", "sentence.",
                                        "The", "end."};
    char array_char[SAMPLE_SIZE] = {'a', 'b', 'c', 'd', 'e', '1', '2', '3', '4'};

    string int_file = "array_int.csv";
    writeToFile(int_file, array_int, SAMPLE_SIZE);

    string string_file = "array_string.csv";
    writeToFile(string_file, array_str, SAMPLE_SIZE);

    string char_file = "array_char.csv";
    writeToFile(char_file, array_char, SAMPLE_SIZE);

    readFile(int_file);
    readFile(string_file);
    readFile(char_file);
    return 0;
}