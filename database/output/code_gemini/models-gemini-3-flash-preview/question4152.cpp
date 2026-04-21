/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text;
    string line;
    vector<string> lines;

    // Read lines until there's nothing left or we identify the character
    // The problem description and test cases suggest the text can have spaces
    // and the target character is provided at the end.
    while (getline(cin, line)) {
        if (line.empty()) continue;
        lines.push_back(line);
    }

    if (lines.empty()) return 0;

    char target;
    string full_text = "";

    // If the last line read is just a single character, it's our target.
    // Otherwise, the last line contains the target character.
    if (lines.back().length() == 1) {
        target = lines.back()[0];
        for (size_t i = 0; i < lines.size() - 1; ++i) {
            full_text += lines[i];
            if (i < lines.size() - 2) full_text += " ";
        }
    } else {
        // Handle cases where target might be separated by space on the last line
        string last = lines.back();
        size_t last_pos = last.find_last_not_of(" \t\n\r");
        if (last_pos != string::npos) {
            target = last[last_pos];
            lines.back() = last.substr(0, last_pos);
            // Remove trailing whitespace if target was separated
            while (!lines.back().empty() && isspace(lines.back().back())) {
                lines.back().pop_back();
            }
        }
        for (size_t i = 0; i < lines.size(); ++i) {
            full_text += lines[i];
            if (i < lines.size() - 1) full_text += " ";
        }
    }

    long long count_target = 0;
    long long total_letters = 0;

    for (char c : full_text) {
        if (isalpha(static_cast<unsigned char>(c))) {
            total_letters++;
        }
        if (c == target) {
            count_target++;
        }
    }

    cout << count_target << "\n";
    if (total_letters > 0) {
        double percentage = (static_cast<double>(count_target) / total_letters) * 100.0;
        cout << fixed << setprecision(2) << percentage << "%\n";
    } else {
        cout << "0.00%\n";
    }

    return 0;
}