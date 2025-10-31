/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

void extractWordsAndNumbers(const string& input, set<string>& words, long long& sum) {
    string currentNumber;
    for (char c : input) {
        if (isalpha(c)) {
            // Ignore if not a letter
            if (currentNumber.size() > 0) {
                sum += stoll(currentNumber);
                currentNumber.clear();
            }
        } else if (isdigit(c)) {
            currentNumber += c;
        }
    }
    if (!currentNumber.empty()) {
        sum += stoll(currentNumber);
    }
    
    stringstream ss(input);
    string word;
    while (ss >> word) {
        words.insert(word);
    }
}

void generateCombinations(string prefix, string remaining, set<string>& words) {
    if (prefix.size() == 3) {
        words.insert(prefix);
        return;
    }
    for (int i = 0; i < remaining.size(); i++) {
        generateCombinations(prefix + remaining[i], remaining, words);
    }
}

int main() {
    string line;
    set<string> words;
    long long sum = 0;

    while (getline(cin, line)) {
        extractWordsAndNumbers(line, words, sum);
    }

    vector<char> letters;
    for (const string& word : words) {
        for (char c : word) {
            if (isalpha(c)) {
                letters.push_back(c);
            }
        }
    }

    sort(letters.begin(), letters.end());
    string uniqueLetters(letters.begin(), letters.end());
    sort(uniqueLetters.begin(), uniqueLetters.end());

    set<string> combinations;
    generateCombinations("", uniqueLetters, combinations);

    string result;
    for (const auto& comb : combinations) {
        if (comb.size() == 3) {
            result += comb;
        }
    }

    cout << result << endl;
    cout << "Rebeka agora esta livre! A senha da cela eh " << sum << endl;

    return 0;
}
