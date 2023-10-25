#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    cout << "Enter your filename: " << endl;
    string filename;
    cin >> filename;
    ifstream infile(filename);
    if (!infile.is_open()){
        cout << "File was unable to open " << endl;
        return 1;
    }
    string full_line, name, day, traffic_day;
    int count = 0, max_traffic = 0;

    while (getline(infile, full_line)) {
        istringstream ss(full_line);
        ss >> day;
        count = 0;
        while(getline(ss, name, ',')) {
            count ++;
        }
        if (count > max_traffic){
            max_traffic = count;
            traffic_day = day;
        }
    }
    cout << traffic_day << " is the busiest day " << endl;
    infile.close();
    return 0;
}