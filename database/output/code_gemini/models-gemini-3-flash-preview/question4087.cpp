/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> words;
    string word;
    while (cin >> word) {
        words.push_back(word);
    }

    if (words.empty()) return 0;

    int area = 0;
    int next_idx = -1;

    // Check neighborhoods based on description
    // Area 1: Moon Knight, Daredevil, Jessica Jones
    // Area 2: WandaVision, Loki, Hawkeye
    if (words[0] == "Daredevil") {
        area = 1;
        next_idx = 1;
    } else if (words[0] == "WandaVision") {
        area = 2;
        next_idx = 1;
    } else if (words[0] == "Loki") {
        area = 2;
        next_idx = 1;
    } else if (words[0] == "Hawkeye") {
        area = 2;
        next_idx = 1;
    } else if (words.size() >= 2) {
        string combined = words[0] + " " + words[1];
        if (combined == "Moon Knight") {
            area = 1;
            next_idx = 2;
        } else if (combined == "Jessica Jones") {
            area = 1;
            next_idx = 2;
        }
    }

    if (area == 0) {
        cout << "Invalid Neighborhood" << endl;
        return 0;
    }

    if (next_idx >= (int)words.size()) {
        cout << "Water not Available" << endl;
        return 0;
    }

    string day = words[next_idx];
    int hour = -1;

    if (next_idx + 1 < (int)words.size()) {
        try {
            hour = stoi(words[next_idx + 1]);
        } catch (...) {
            hour = -1;
        }
    } else {
        // According to the logic, if the hour is not provided, 
        // we can't confirm availability.
        cout << "Water not Available" << endl;
        return 0;
    }

    // Supply Schedule Logic:
    // Area 1: Tuesday, 8 am to 8 pm (8:00 - 20:00)
    // Area 2: Wednesday, from 2 am onwards
    if (area == 1) {
        if (day == "Tuesday" && hour >= 8 && hour <= 20) {
            cout << "Water Available" << endl;
        } else {
            cout << "Water not Available" << endl;
        }
    } else if (area == 2) {
        if (day == "Wednesday" && hour >= 2) {
            cout << "Water Available" << endl;
        } else {
            cout << "Water not Available" << endl;
        }
    } else {
        cout << "Water not Available" << endl;
    }

    return 0;
}