#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void compareAttendanceSheet(string first_attendance_file, string second_attendance_file){
    vector<string> first_file;
    vector<string> second_file;
    vector<string> temp;
    string name1, name2;
    ifstream infile1(first_attendance_file);
    ifstream infile2(second_attendance_file);
    if (!infile1.is_open() || !infile2.is_open()){
        cout << "Failed to open attendance files" << endl;
        return;
    }
    while(getline(infile1, name1)){
        first_file.push_back(name1);
    }
    while(getline(infile2, name2)){
        second_file.push_back(name2);
    }
    int length1 = first_file.size();
    int length2 = second_file.size();
    for (int i = 0; i < length1; i++){
        bool no_match = false;
        for (int j = 0; j < length2; j++){
            if (first_file[i] == second_file[j]){
                no_match = true;
            }
        }
        if(!no_match){
            temp.push_back(first_file[i]);
        }
    }
    /*
    for (int i = 0; i < temp.size(); i++){
        cout << temp[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < first_file.size(); i++){
        cout << first_file[i] << endl;
    }
    cout << endl;
    */
    if (temp.size() == 0){
        cout << "Every student has boarded the bus. It's time to leave. " << endl;
        return;
    }
    else{
        cout << "Students yet to board the bus are" << endl;
        int tempsize = temp.size();
        for (int i = 0; i < tempsize; i++){
            cout << temp[i] << endl;
        }
        return;
    }
}

int main() {
    string first_attendance_file = "attendance_sheet_1.txt";
    string second_attendance_file = "attendance_sheet_2.txt";
    compareAttendanceSheet(first_attendance_file, second_attendance_file);
    return 0;
}