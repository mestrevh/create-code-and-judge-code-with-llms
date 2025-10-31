/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int maxLineLength;
    cin >> maxLineLength;
    cin.ignore();

    string input;
    getline(cin, input);
    
    stringstream ss(input);
    vector<string> words;
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    vector<string> lines;
    string currentLine = words[0];
    
    for (int i = 1; i < words.size(); ++i) {
        if (currentLine.length() + 1 + words[i].length() <= maxLineLength) {
            currentLine += " " + words[i];
        } else {
            lines.push_back(currentLine);
            currentLine = words[i];
        }
    }
    lines.push_back(currentLine);

    for (const auto& line : lines) {
        cout << line << endl;
    }
    
    return 0;
}
