/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string trim(const string& s) {
    size_t first = s.find_first_not_of(" \t\n\r");
    if (string::npos == first) return "";
    size_t last = s.find_last_not_of(" \t\n\r");
    return s.substr(first, (last - first + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) return 0;

    stringstream ss(line);
    string token;
    vector<string> gerunds;
    int count = 0;

    while (getline(ss, token, ',')) {
        string word = trim(token);
        if (word.length() >= 2) {
            string suffix = word.substr(word.length() - 2);
            if (suffix == "ar" || suffix == "er" || suffix == "ir" || suffix == "or") {
                count++;
                string gerund = word.substr(0, word.length() - 1) + "ndo";
                gerunds.push_back(gerund);
            }
        }
    }

    cout << count << "\n";
    for (const string& g : gerunds) {
        cout << g << "\n";
    }

    return 0;
}

