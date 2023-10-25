#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> teamsInTournament(string teamscores_file, int wins, int goals){
    vector<string> qualified_teams;
    ifstream infile(teamscores_file);
    if (!infile.is_open()){
        cout << "Failed to open team scores file" << endl;
    }
    string full_line, name, win_count, goal_count = "";
    while (getline(infile, full_line)){
        istringstream ss(full_line);
        getline(ss, name, ',');
        getline(ss, win_count, ',');
        getline(ss, goal_count, ',');

        if (stoi(win_count) > wins){
            qualified_teams.push_back(name);
        }
        else if(stoi(win_count) == wins){
            if (stoi(goal_count) >= goals){
                qualified_teams.push_back(name);
            }
        }
    }
    return qualified_teams;
    
}

int main() {
    string filename;
    int wins, goals;
    vector<string> qualified_teams;
    cout << "Enter teamscores filename" << endl;
    cin >> filename;
    cout << "Enter number of wins required" << endl;
    cin >> wins;
    cout << "Enter number of goals scored for tie-breaker" << endl;
    cin >> goals;
    qualified_teams = teamsInTournament(filename, wins, goals);
    int size = qualified_teams.size();
    if (size > 0){
        cout << "Qualified teams are" << endl;
        for (int i = 0; i < size; i++){
            cout << qualified_teams[i] << endl;
        }
    }
    else{
        cout << "No qualifying teams found" << endl;
    }

    return 0;
}