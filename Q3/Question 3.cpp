#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int keywordThreshold(string keyword_file, string keyword_threshold[][2]) {
    int count = 0;
    string full_line, word, num = "";
    ifstream infile(keyword_file);
    if (!infile.is_open()) {
        cout << "Failed to open keyword file" << endl;
        return 0;
    }
    while (getline(infile, full_line)) {
        istringstream ss(full_line);
        ss >> word;
        ss >> num;
        keyword_threshold[count][0] = word;
        keyword_threshold[count][1] = num;
        count ++;
    }
    return count;
}

bool countFilter(string email_file, string keyword_threshold[][2], int keyword_count[], int keyword_size){
    ifstream infile{email_file};
    if (!infile.is_open()){
        cout << "Failed to open email file" << endl;
        return false;
    }
    string full_line, word = "";
    while (infile >> word){
        for (int i = 0; i < keyword_size; i++){
            if (word == keyword_threshold[i][0]){
                keyword_count[i] += 1;
            }
        }
    }
    return true;
}

bool checkSpam(int keyword_count[], string keyword_threshold[][2], int keyword_size) {
    bool is_spam = true;
    for (int i = 0; i < keyword_size; i++) {
        if (keyword_count[i] < stoi(keyword_threshold[i][1])) {
            is_spam = false;
        }
    }
    if (is_spam){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    string email_file = "email_not_spam.txt";
    string keyword_file = "keywords_1.txt";
    string keyword_threshold[10][2];
    int keyword_count[10] = {0,0,0,0,0,0,0,0,0,0};
    int keyword_size = 0;
    bool read_email_file, spam_email;
    keyword_size = keywordThreshold(keyword_file, keyword_threshold);
    if(!keyword_size) {
        return 0;
    }
    read_email_file = countFilter(email_file, keyword_threshold, keyword_count, keyword_size);
    if(!read_email_file) {
        return 0;
    }
    spam_email = checkSpam(keyword_count, keyword_threshold, keyword_size);
    if(spam_email) {
        cout << "It's a spam email!!" << endl;
    }
    else {
        cout << "It's not a spam email!!" << endl;
    }
}