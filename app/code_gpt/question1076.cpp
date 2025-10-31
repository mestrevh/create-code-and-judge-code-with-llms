/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void justifyText(const vector<string>& words, int lineWidth) {
    int n = words.size();
    vector<string> lines;
    string currentLine;
    int currentLength = 0;

    for (int i = 0; i < n; ++i) {
        int wordLength = words[i].size();
        if (currentLength + currentLine.size() + wordLength > lineWidth) {
            for (int j = 0, spaces = lineWidth - currentLength; j < currentLine.size() - 1; ++j) {
                if (spaces > 0) {
                    currentLine[j] += ' ';
                    spaces--;
                }
                if (j < (currentLine.size() - 1) - (currentLine.size() - 2 - spaces)) {
                    currentLine[j] += (spaces > 0);
                }
            }
            lines.push_back(currentLine);
            currentLine = words[i];
            currentLength = wordLength;
        } else {
            if (!currentLine.empty()) currentLine += ' ';
            currentLine += words[i];
            currentLength += wordLength;
        }
    }
    lines.push_back(currentLine);

    for (int i = 0; i < lines.size(); ++i) {
        cout << lines[i] << endl;
    }
}

int main() {
    int P, C;
    cin >> P >> C;
    cin.ignore();
    string input;
    getline(cin, input);

    istringstream iss(input);
    vector<string> words;
    string word;
    while (iss >> word) {
        words.push_back(word);
    }

    justifyText(words, C);
    return 0;
}
