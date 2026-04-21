/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    if (!(cin >> M)) return 0;

    vector<string> frags(3);
    for (int i = 0; i < 3; ++i) {
        cin >> frags[i];
    }

    string line;
    getline(cin, line);

    string best_name = "";
    int best_count = -1;
    int best_sum = -1;
    bool tie = false;

    int processed = 0;
    while (processed < M && getline(cin, line)) {
        if (line.empty()) continue;
        size_t pos = line.find('-');
        if (pos == string::npos) continue;

        string name = line.substr(0, pos);
        string dna = line.substr(pos + 1);

        while (!name.empty() && (name.back() == ' ' || name.back() == '\t' || name.back() == '\r' || name.back() == '\n')) 
            name.pop_back();
        while (!name.empty() && (name.front() == ' ' || name.front() == '\t' || name.front() == '\r' || name.front() == '\n')) 
            name.erase(0, 1);
        while (!dna.empty() && (dna.back() == ' ' || dna.back() == '\t' || dna.back() == '\r' || dna.back() == '\n')) 
            dna.pop_back();
        while (!dna.empty() && (dna.front() == ' ' || dna.front() == '\t' || dna.front() == '\r' || dna.front() == '\n')) 
            dna.erase(0, 1);

        int current_count = 0;
        int current_sum = 0;
        for (int j = 0; j < 3; ++j) {
            if (!frags[j].empty() && dna.find(frags[j]) != string::npos) {
                current_count++;
                current_sum += (int)frags[j].length();
            }
        }

        if (current_count > best_count) {
            best_count = current_count;
            best_sum = current_sum;
            best_name = name;
            tie = false;
        } else if (current_count == best_count) {
            if (current_sum > best_sum) {
                best_sum = current_sum;
                best_name = name;
                tie = false;
            } else if (current_sum == best_sum) {
                tie = true;
            }
        }
        processed++;
    }

    if (tie) {
        cout << "Nao pegamos x pilantra desse vez..." << endl;
    } else {
        cout << "X reponsavel por essa atrocidade foi " << best_name << "!" << endl;
    }

    return 0;
}