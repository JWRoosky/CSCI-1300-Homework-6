#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int split(string input_string, char separator, string arr[], const int arr_size){
    istringstream ss(input_string);
    string segment = "";
    int counter = 0;
    while(getline(ss, segment, separator)){
        if(counter >= arr_size){
            return -1;
        }
        arr[counter] = segment;
        counter ++;
    }
    return counter;
}

int main(){
    string testcase = "Bangkok,Berlin,Birmingham,Bogota,Busan,Baton Rouge,Beaumont,Boise,Budapest";
    char separator = ',';
    const int arr_size = 5;
    string arr[arr_size];
    // num_splits is the value returned by split
    int num_splits = split(testcase, separator, arr, arr_size);
    cout << "Function returned value: " << num_splits << endl;
    if(num_splits != -1) {
        for (int i=0; i < num_splits; i++){
            cout << "arr["<< i << "]: " << arr[i] << endl;
        }   
    }
    return 0;
}